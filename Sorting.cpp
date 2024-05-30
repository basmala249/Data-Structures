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
