//
// Created by L on 2019/11/19.
//
#include "AVL.h"
tree rightRotation(const tree& avl) {
    //the precondition is its left subtree is not empty;
    tree D = avl;
    tree B = left(avl);
    tree C = right(B);

    B->setRight(D);
    D->setLeft(C);
    return B;
}
tree leftRotation(const tree& avl) {
    //the precondition is its right subtree is not empty;
    tree B = avl;
    tree D = right(B);
    tree C = left(D);

    D->setLeft(B);
    B->setRight(C);
    return D;
}

tree leftRight_rotation(const tree& avl) {
    //the precondition is that right(left(avl)) is not emptyTree();
    tree B = left(avl);
    B = leftRotation(B);
    avl->setLeft(B);

    return rightRotation(avl);
}

tree rightLeft_rotation(const tree& avl) {
    //the precondition is that left(right(avl)) is not emptyTree();

    tree D = right(avl);
    D = rightRotation(D);
    avl->setRight(D);

    return leftRotation(avl);
}

void AVL::check()  {
    if(height(avl) < 3)
        return;

    int bal = delta(avl);//delta(avl)
    int bal_L;//delta(left(avl))
    int bal_R;//delta(right(avl))

    if(2 == bal) {
        bal_L = delta(left(avl));
        if(bal_L >= 0 ) {
            avl = rightRotation(avl);
        } else {
            avl = leftRight_rotation(avl);
        }
    } else if(-2 == bal) {
        bal_R = delta(right(avl));
        if(bal_R <= 0) {
            avl = leftRotation(avl);
        } else {
            avl = rightLeft_rotation(avl);
        }
    }
}
int AVL::delta(const tree &tree1)  {
    int i = height(left(tree1));
    int j = height(right(tree1));

    return i - j;
}
void AVL::Insert(const Data &data)  {
    avl = insert(data, avl);
    check();
}
void AVL::Delete(const Data &data)  {
    avl = deleteNode(data, avl);
    check();
}
AVL& AVL::operator=(const AVL &avl1) {
    if(this == &avl1) return *this;

    release(avl);
    avl = copy_tree(avl1.avl);
    return *this;
}
bool AVL::in(const Data &data) {
    if(isInBst(data, avl)) return true;
    return false;
}