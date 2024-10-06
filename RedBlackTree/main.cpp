#include <iostream>
#include "redBlackTree.h"
using namespace std;


int main() {
    redBlackTree  tree;
    int n ;
    cin >> n ;
    while(n--) {
        int a;
        cin >> a;
        tree.insert(a);
        tree.print();
    }
    return 0;
}
