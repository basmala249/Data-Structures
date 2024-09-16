//
// Created by HP on 9/16/2024.
//

#include "Vector.h"
#include <iostream>

using namespace std;
Vector ::Vector() {
    size = 0;
    arr = new int[200];
}

Vector ::Vector(int maxSize) {
    size = 0;
    if(maxSize < 0)maxSize = 1;
    arr = new int[maxSize];
}

int Vector::get(int indx) {
    if(indx < 0 or indx >= size){
        return -1;
    }
    return arr[indx];
}

void Vector::set(int indx, int val) {
    if(indx < 0 or indx > size){
        return ;
    }
    if(indx == size)size++;
    arr[indx] = val ;
}

void Vector::print() {
    for(int i = 0 ; i < size ; ++i){
        cout << arr[i] << " ";
    }
    cout << '\n';
}

int Vector::find(int val) {
    for(int i = 0 ; i < size ; ++i){
        if(arr[i] == val)return i;
    }
    return -1;
}

Vector ::~Vector() {
    delete [] arr;
    arr = nullptr;
}
