//
// Created by L on 2019/11/2.
//

#ifndef MY_BINARY_TREE_1_0_BST_H
#define MY_BINARY_TREE_1_0_BST_H

#include "tree.h"
//insert a node in a bst, and you must make sure that there is no same nodes!!!
void initial(tree& bst);
tree insert(const Data& data, const tree& bst);
void show_bst(tree bst);

//check whether a node is in a bst,
// and if not, it will return nullptr otherwise it will return its pointer
tree isInBst(const Data& data, tree bst);


//to find the smallest node in a bst tree, and it serves for delete operation about bst
const Data& smallestNode(tree bst);
tree removeSmallestNode(const tree& t);
//delete a node in bst
tree deleteNode(const Data& data, const tree& bst);


#endif //MY_BINARY_TREE_1_0_BST_H
