/* i decide to create a binary-tree,
 * a class of tree*/
#include <iostream>
#include "tree.h"
using namespace std;

int main() {
    string str = "hello";

    tree  tree1 = makeTree(3, makeTree(1, leaf(2), leaf(3)), emptyTree());
    cout << root(tree1) << endl;
    cout << size(tree1) << endl;

    Data data1 = 3;
    Data data2 = 4;

    if(data1 < 5) {
        cout << "true" << endl;
    }
    if(data1 == data2) {
        cout << "ok" << endl;
    }

    release(tree1);

    return 0;
}