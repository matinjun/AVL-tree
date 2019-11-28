//
// Created by L on 2019/10/23.
//

#include "tree.h"
tree emptyTree() { return nullptr;}
tree makeTree(const Data& data,const tree& leftTree, const tree& rightTree) {
    auto tree1 = new Node(data, leftTree, rightTree);
    return tree1;
}
bool isEmpty(const tree& tree1) { return nullptr == tree1;}
const Data& root(const tree& tree1) {
    if(isEmpty(tree1)) {
        exit(1);
    }
    return tree1->data;
}
tree left(const tree& tree1) {
    if(isEmpty(tree1)) {
        return emptyTree();
    }
    return tree1->getLeft();
}
tree right(const tree& tree1) {
    if(isEmpty(tree1)) {
        return emptyTree();
    }
    return tree1->getRight();
}
void release(const tree& tree1) {
    if(isEmpty(tree1)) {
        return;
    }
    release(left(tree1));
    release(right(tree1));
    delete tree1;
}
tree leaf(const Data& data) { return makeTree(data, emptyTree(), emptyTree());}
unsigned int size(const tree& tree1) {
    if(isEmpty(tree1)) {
        return 0;
    }
    return 1 + size(left(tree1)) + size(right(tree1));
}


unsigned int height(const tree& tree1) {
    if(isEmpty(tree1)) return 0;
    unsigned int i = height(left(tree1));
    unsigned int j = height(right(tree1));
    if(i < j) return 1 + j;
    return 1 + i;
}

//return a tree copying tree1
tree copy_tree(const tree& tree1) {
    if(isEmpty(tree1)) {
        return emptyTree();
    }
    return makeTree(root(tree1), copy_tree(left(tree1)), copy_tree(right(tree1)));
}
