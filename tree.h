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
tree makeTree(const Data& data, const tree& leftTree, const tree& rightTree);
bool isEmpty(const tree& tree1);
const Data& root(const tree& tree1) ;
tree left(const tree& tree1);
tree right(const tree& tree1);
void release(const tree& tree1);
tree leaf(const Data& data);
unsigned int size(const tree& tree1);
unsigned int height(const tree& tree1);
//return a tree copying tree1
tree copy_tree(const tree& tree1);

#endif //MY_BINARY_TREE_1_0_TREE_H
