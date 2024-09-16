//
// Created by HP on 9/16/2024.
//

#include "Vector.h"
#include <iostream>

using namespace std;
Vector ::Vector() {
    size = 0;
    maxSize = 200;
    arr = new int[maxSize];
}

Vector ::Vector(int maxSize) {
    size = 0;
    this -> maxSize = maxSize;
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

int Vector::front() {
    if(size > 0)return arr[0];
    return -1;
}

int Vector::back() {
    if(size > 0)return arr[size - 1];
    return -1;
}

void Vector::push_back(int val) {
    if(size < maxSize){
        arr[size++] = val;
        return ;
    }
    cout << "Fully\n";
    inCapacity();
    arr[size++] = val;
}

void Vector::insert(int indx, int val) { //O(n)
    if(indx < 0 or indx > size)return;
    if(size == maxSize)inCapacity();
    for(int i = size ; i > indx ; --i){
        arr[i] = arr[i - 1];
    }
    arr[indx] = val;
    size++;
}

void Vector::inCapacity() {
    int *arr2 = (new int[maxSize * 2]);
    for(int i = 0 ; i < size ; ++i) {
        arr2[i] = arr[i];
    }
    maxSize *= 2;
    swap(arr2 , arr);
    delete [] arr2;
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
