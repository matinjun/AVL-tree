//
// Created by L on 2019/10/23.
//

#include "tree.h"
tree emptyTree() { return nullptr;}
tree makeTree(Data data, tree leftTree, tree rightTree) {
    auto tree1 = new Node(data, leftTree, rightTree);
    return tree1;
}
bool isEmpty(tree tree1) { return nullptr == tree1;}
Data root(tree tree1) {
    if(isEmpty(tree1)) {
        exit(1);
    }
    return tree1->data;
}
tree left(tree tree1) {
    if(isEmpty(tree1)) {
        return emptyTree();
    }
    return tree1->getLeft();
}
tree right(tree tree1) {
    if(isEmpty(tree1)) {
        return emptyTree();
    }
    return tree1->getRight();
}
void release(tree tree1) {
    if(isEmpty(tree1)) {
        return;
    }
    release(left(tree1));
    release(right(tree1));
    delete tree1;
}
tree leaf(Data data) { return makeTree(data, emptyTree(), emptyTree());}
unsigned int size(tree tree1) {
    if(isEmpty(tree1)) {
        return 0;
    }
    return 1 + size(left(tree1)) + size(right(tree1));
}
