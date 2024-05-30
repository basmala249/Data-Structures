// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
//A array , i index of element , m size of array
void maxHeapify(int A[] , int i , int n){
    //cout << A[i] << "Point\n";
    int l = 2 * i;//Get left of node
    int r = (2 * i) + 1;//get right of node
    int large = i;//save largest value of each node
    if(l <= n and A[l] > A[large]){
       // cout << A[l] << endl;
        //check for greatest
        large = l;//exchange with left child
    }
    if(r  <= n and A[r] > A[large]){
        //cout << A[r] << endl;
        large = r;//exchange with right child
    }
    if(large != i){
        //check to prevent exchanging same nodes
        int temp = A[i];
        A[i] = A[large];
        A[large] = temp;
        //exchange nodes
         maxHeapify(A , large , n);//recursion to sort all heap
     //large new value
    }
    return;
}
//Build heap from unsorted array
void BuildHeap(int A[] , int n){
    //nodes greater than n / 2 are leaves (no children)
    //start point is 1
    for(int i = (n / 2 ); i >= 1 ; --i){
        maxHeapify(A , i , n);//to maintain heap
    }
}
void HeapSort(int A[] , int n){
    cout << A[1] << " ";
   if(n == 1){
       return;
   }
   A[1] = A[n];
   maxHeapify(A,1,n - 1);
   HeapSort(A,n - 1);
}

int extractMax(int A[] , int n){
    if(n < 1) return -1;
    int max  = A[1];
    A[1] = A[n];
    maxHeapify(A , 1 , n - 1);
    return max;
}

int maximum(int A[]){
    return A[1];
}

void increaseKey(int A[] ,int i , int key){
    if(key < A[i] ){
        A[i] = key;
        return;
    }
    A[i] = key;
    int parent = i / 2;
    while(i > 1 and A[parent] < A[i]){
        swap(A[parent] , A[i]);
        i = parent;
        parent = i / 2;
    }
}

void heapInsert(int A[] , int& n , int key){
    A[n] = key - 1;
    increaseKey(A,n,key);
    return ;
}
int main() {
    int arr[] = {0, 1, 13 , 0 , 50};
    int n = 4;
    BuildHeap(arr , n);
    for(int i = 1 ; i <= n;++i){
        cout << arr[i] << " ";
    }
    cout << endl;
    n += 1;
    heapInsert(arr, n , 100);
    cout << "n: " << n << endl;
    for(int i = 1 ; i <= n;++i){
        cout << arr[i] << " ";
    }
    return 0;
}
