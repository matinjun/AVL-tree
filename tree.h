//
// Created by L on 2019/10/23.
//

#ifndef MY_BINARY_TREE_1_0_TREE_H
#define MY_BINARY_TREE_1_0_TREE_H


#include <iostream>
#include <ostream>
#include "NODE.h"
using tree = Node*;

/*
 * • EmptyTree, which returns an empty tree,
 * • MakeTree(v, l, r), which builds a binary tree from a root node with label v and two
 * constituent binary trees l and r,
 * a condition to test whether a tree is empty:
 * • isEmpty(t), which returns true if tree t is the EmptyTree,
 * and three selectors to break a non-empty tree into its constituent parts:
 * • root(t), which returns the value of the root node of binary tree t,
 * • left(t), which returns the left sub-tree of binary tree t,
 * • right(t), which returns the right sub-tree of binary tree t.
*/
tree emptyTree();
tree makeTree(Data data, tree leftTree, tree rightTree);
bool isEmpty(tree tree1);
Data root(tree tree1) ;
tree left(tree tree1);
tree right(tree tree1);
void release(tree tree1);
tree leaf(Data data);
unsigned int size(tree tree1);

#endif //MY_BINARY_TREE_1_0_TREE_H
