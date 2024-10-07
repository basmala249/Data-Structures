#include <iostream>
#include "redBlackTree.h"
using namespace std;
//7
// 19 13 15 7 3 6 4

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
