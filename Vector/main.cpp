#include <iostream>
#include "Vector.h"

using namespace std;
int main() {
    Vector v(10);
    for(int i = 0 ; i < 10 ; ++i){
        v.set(i , i);
    }
    v.insert(2 , 1000);
    v.print();
    v.push_back(34);
    cout << v.find(34) << " " << v.find(3) << '\n';
    return 0;
}
