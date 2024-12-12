#ifndef SUFFIXARRAY_H
#define SUFFIXARRAY_H

#include <iostream>
using namespace std;

template <typename T>
//Sorting O(nlogn)
void mergeSort(int left, int mid, int right, T* arr) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    T* L = new T[n1];
    T* R = new T[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}

template <typename T>
void merge(int left, int right, T arr[]) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    merge(left, mid, arr);
    merge(mid + 1, right, arr);
    mergeSort(left, mid, right, arr);
}
//SuffixNode 
template <typename T>
struct SuffixPair {
    int index;//Index stored at
    T first;//first h elemnts 
    T second;// last h elemnts
    SuffixPair() : index(0), first(0), second(0) {}
    SuffixPair(int idx, T f, T s) : index(idx), first(f), second(s) {}
    //for sorting
    bool operator<(const SuffixPair<T>& other) const {
        if (first != other.first) {
            return first < other.first;
        }
        return second < other.second;
    }
    //for comparsion
    bool operator==(const SuffixPair<T>& other) const {
        return first == other.first && second == other.second;
    }
   //for printing
    friend ostream& operator<<(ostream& os, const SuffixPair<T>& p) {
        os << p.index << " " << p.first << " " << p.second << '\n';
        return os;
    }
};

class SuffixArray {
    char* suffix;//String to Get Suffixes
    int* Vals;//order after sorted
    int size;
    void InitalizeVal();//to get K = 1
    int GetMax();to compare with size to break
public:
    SuffixArray(const char* sffx);
    ~SuffixArray();
    void ConstructUsingPrefixDoubling();
    void Print() const;
};

SuffixArray::SuffixArray(const char* sffx) {
    size = 0;
    //coping string in to suffix till null pointer
    while (sffx[size] != '\0') {
        size++;
    }
    bool endsWithDollar = (size > 0 && sffx[size - 1] == '$');
    if (endsWithDollar) {
        suffix = new char[size + 1];
    } else {
        suffix = new char[size + 2];
    }
    for (int i = 0; i < size; ++i) {
        suffix[i] = sffx[i];
    }
    if (!endsWithDollar) {
        suffix[size] = '$';
        size++;
    }
    suffix[size] = '\0';
    Vals = new int[size];
    InitalizeVal();
}

int SuffixArray::GetMax() {
    int mx = 0;
    for(int i = 0 ; i < size ; ++i) {
        mx = max(mx , Vals[i]);
    }
    return mx;
}

void SuffixArray::InitalizeVal() {
    SuffixPair<char> arr[size];
    //first Store
    for (int i = 0; i < size; i++) {
        arr[i] = SuffixPair<char>(i, suffix[i], suffix[i]);
    }
    //Sort
    merge(0, size - 1, arr);
    int Start = 0;
    //fill Array
    Vals[arr[0].index] = Start++;
    for (int i = 1; i < size; i++) {
        if(arr[i] == arr[i - 1]) {
            Vals[arr[i].index] = Vals[arr[i - 1].index];
        }
        else {
            Vals[arr[i].index] = Start++;
        }
    }
}

void SuffixArray::ConstructUsingPrefixDoubling() {
    int mx = GetMax();
    int start = 1;
    SuffixPair<int> arr[size];
    while(mx != size - 1) {
        //loops till there is no duplicates exits
       for(int i = 0; i < size; i++) {
           SuffixPair<int> p = SuffixPair<int>(i, Vals[i] , Vals[min(size - 1 , i + start)]);
           arr[i] = p;
       }
       merge(0, size - 1, arr);
       int Start = 0;
       Vals[arr[0].index] = Start++;
       for (int i = 1; i < size; i++) {
            if(arr[i] == arr[i - 1]) {
                Vals[arr[i].index] = Vals[arr[i - 1].index];
            }
            else {
                Vals[arr[i].index] = Start++;
            }
       }
       start++;
       mx = GetMax();
    }
    //when finish fill index order from high to low to help for search
    for(int i = 0; i < size; i++) {
        Vals[i] = arr[i].index;
    }
}
//printing Indexes
void SuffixArray::Print() const {
    for (int i = 0; i < size; ++i) {
        cout << Vals[i] << " ";
    }
    cout << '\n';
}
//delete pointers
SuffixArray::~SuffixArray() {
    delete[] suffix;
    delete[] Vals;
}

#endif
