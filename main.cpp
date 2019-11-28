/* i decide to create a binary-tree,
 * a class of tree*/
#include <iostream>
#include "AVL.h"
using namespace std;

int main() {
    string str = "hello";
/*
 * for testing tree!!!
    tree  tree1 = makeTree(3, makeTree(1, leaf(2), leaf(3)), emptyTree());

    cout << root(left(tree1)) << endl;
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
*/
//test for bst insert
    tree bst;
    initial(bst);

    for(int i: {5, 7, 4, 11, 1, 5, -1, 0}) {
        bst = insert(i, bst);
    }
    show_bst(bst);
    cout << endl << endl;
    if(isInBst(100, bst)) cout << "yes" << endl;
    else cout << "no" << endl;

    if(isInBst(0, bst)) cout << "yes" << endl;
    else cout << "no" << endl;
    cout << endl;

    for(int i: {4, 9, 0, -1}) {
        bst = deleteNode(i, bst);
        show_bst(bst);
        cout << endl;

        cout << "leftRotation" << endl;
        bst = leftRotation(bst);
        show_bst(bst);
        cout << endl;

        cout << "rightRotation" << endl;
        bst = rightRotation(bst);
        show_bst(bst);
        cout << endl;
    }

    release(bst);

    cout << endl << "-------------------" << endl;

    AVL avl;
    for(int i: {5, 4, 9, 3, 7, 6, 2, 10}) {
        avl.Insert(i);
        avl.print();
        cout << endl << "------" << endl;
    }
    avl.Delete(10);
    avl.print();
    cout << endl << "------" << endl;
    avl.Delete(10);
    avl.print();
    cout << endl << "------" << endl;

    cout << endl << endl;
    cout << "---------is In? ----------" << endl;
    if(avl.in(7)) {
        cout << 7 << " is in AVL tree" << endl;
    }
    if(!avl.in(19)) {
        cout << 19 << " is not in AVL tree" << endl;
    }
    if(!avl.empty()) {
        cout << "the AVL tree is not null" << endl;
    }
    return 0;
}