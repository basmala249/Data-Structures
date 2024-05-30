// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void InsertionSort(int A[] , int n){
    for(int i = 1 , j ; i < n ; ++i){
        int temp = A[i];
        for(j = i - 1  ; j >= 0 and temp < A[j] ; --j){
            A[j + 1] = A[j];
        }
        if(i != j + 1)
         A[j + 1] = temp;
   
    }
}

void SelectionSort(int A[] , int n){
    for(int i = 0 ; i < n - 1 ; ++i){
        int least = i;
        for(int j = i + 1 ; j < n ; ++j ){
            if(A[least] > A[j]){
                least = j;
            }
        }
        if(least != i){
            swap(A[i] , A[least]);
        }
    }
}

void bubbleSort(int A[] , int n){
    for (int  i = 0 ; i < n - 1 ; ++i){
        bool sawp = false;
        for(int j = n - 1 ; j > i ; --j){
            if(A[j] < A[j - 1] ){
                swap(A[j] , A[j - 1]);
                sawp = true;
            }
        }
        if(!sawp)break;
    }
}


void print(int arr[] , int n){
    for(int j = 0 ; j < n ; ++j){
            cout <<  arr[j] << " ";
        }
        cout << endl;
}
int main() {
    int n ;
    cin >> n;
    int arr[n];
    for(int j = 0 ; j < n ; ++j){
            cin >> arr[j];
        }
    InsertionSort(arr,n);
    print(arr,n);
    return 0;
}
