#include <iostream>
#include "Vector.h"

using namespace std;
int main() {
    Vector v(10);
    for(int i = 0 ; i < 10 ; ++i){
        v.set(i , i);
    }
    v.print();
    cout << v.find(55) << " " << v.find(3) << '\n';
    return 0;
}
