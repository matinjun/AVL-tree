//
// Created by L on 2019/11/19.
//

#ifndef MY_BINARY_TREE_1_0_AVL_H
#define MY_BINARY_TREE_1_0_AVL_H

#include "bst.h"

/*
 * providing that there is an avl tree T, when you insert or delete a node,
 * delta = height(left(T)) - height(right(T))
 * the abs(delta) = abs(height(left(T)) - height(right(T))) will be at most 2.
 * if delta is  2, you should
 * B = left(T)
 * ````if height(left(B)) >= height(right(B)), just rightRotation(T)
 * ````if else,                              , leftRotation(B) first, then rightRotation(T) OR leftRight_rotation(T)
 * if delta is -2, you should
 * D = right(T)
 * ````if height(right(D)) >= height(left(D)), just leftRotation(T)
 * ````if else,                              , rightRotation(D) first, then leftRotation(T) OR rightLeft_rotation(T)*/
tree rightRotation(const tree& avl);//the precondition is its left subtree is not empty;
tree leftRotation(const tree& avl);//the precondition is its right subtree is not empty;
tree leftRight_rotation(const tree& avl);//the precondition is that right(left(avl)) is not emptyTree();
tree rightLeft_rotation(const tree& avl);//the precondition is that left(right(avl)) is not emptyTree();

class AVL {
private:
    tree avl;
public:
    AVL():avl(emptyTree()) {}
    AVL(const AVL& AVL1): avl(copy_tree(AVL1.avl)) {}
    ~AVL() { release(avl); }
    AVL&operator= (const AVL& avl1);

private:
    //compute height(left(tree1)) - height(right(tree1))
    //note that tree1 is not an empty tree;
    int delta(const tree& tree1);

private:
    void check();
public:
    void Insert(const Data& data);
    void Delete(const Data& data);
    void print() { show_bst(avl); }
    bool in(const Data& data);
    bool empty() { return isEmpty(avl);}
};

#endif //MY_BINARY_TREE_1_0_AVL_H
