//
// Created by L on 2019/11/1.
//

#ifndef MY_BINARY_TREE_1_0_NODE_H
#define MY_BINARY_TREE_1_0_NODE_H

#include "Data.h"
class Node {
public:
    explicit Node(Data data1, Node* l = nullptr, Node* r = nullptr):data(data1), left(l), right(r) {}
    //void setLeft(Node* p) { left = p;}
    //void setRight(Node* p) { right = p;}
    Node* getLeft() { return left;}
    Node* getRight() { return right;}

public:
    Data data;
private:
    Node* left;
    Node* right;
};

#endif //MY_BINARY_TREE_1_0_NODE_H
