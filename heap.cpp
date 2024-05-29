#include <iostream>
using namespace std;
//A array , i index of element , m size of array
void maxHeapify(int A[] , int i , int n){
    int l = 2 * i;//Get left of node
    int r = (2 * i) + 1;//get right of node
    int large = i;//save largest value of each node
    if(l <= n and A[l] > A[large]){
        //check for greatest
        large = l;//exchange with left child
    }
    if(r  <= n and A[r] > A[large]){
        large = r;//exchange with right child
    }
    if(large != i){
        //check to prevent exchanging same nodes
        int temp = A[i];
        A[i] = A[large];
        A[large] = temp;
        //exchange nodes
    }
     maxHeapify(A , large , n);//recursion to sort all heap
     //large new value
}
