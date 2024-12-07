#include <iostream>
#include "BTree.h"
using namespace std;
int main() {
    BTree<int,3> t1;

    t1.Insert(300);
    t1.Insert(39);
    t1.Insert(230);
    t1.Insert(213);
    t1.Insert(29);
    t1.Insert(385);
    t1.Insert(161);
    t1.Insert(377);
    t1.Insert(277);
    t1.Insert(335);
    t1.Insert(400);t1.Insert(500);t1.Insert(550);t1.Insert(575);t1.Insert(600);t1.Insert(625);
    t1.Print(); // Should output the following on the screen:
    // Construct a BTree of order 3, which stores int data
    cout << "=========================================================================\n";
    BTree<int,3> t2;

    t2.Insert(1);
    t2.Insert(5);
    t2.Insert(0);
    t2.Insert(4);
    t2.Insert(3);
    t2.Insert(2);

    t2.Print(); // Should output the following on the screen:
    /*
    1,4
      0
      2,3
      5
    */
    cout << "=========================================================================\n";
    // Construct a BTree of order 5, which stores char data
    BTree<char,5> t;

    // Look at the example in our lecture:
    t.Insert('G');
    t.Insert('I');
    t.Insert('B');
    t.Insert('J');
    t.Insert('C');
    t.Insert('A');
    t.Insert('K');
    t.Insert('E');
    t.Insert('D');
    t.Insert('S');
    t.Insert('T');
    t.Insert('R');
    t.Insert('L');
    t.Insert('F');
    t.Insert('H');
    t.Insert('M');
    t.Insert('N');
    t.Insert('P');
    t.Insert('Q');

    t.Print(); // Should output the following on the screen:

    /*
    K
    C,G
    A,B
    D,E,F
    H,I,J
    N,R
    L,M
    P,Q
    S,T
    */
}
