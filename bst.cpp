//
// Created by L on 2019/11/2.
//
#include "bst.h"
void initial(tree& bst) {
    bst = emptyTree();
}
tree insert(const Data& data, const tree& bst) {
    /*
    • If the given tree is empty or equal to the value of root, then simply assign the new value v to the root, and leave the
    left and right subtrees empty
    • If the given tree is non-empty, then insert a node with value v as follows:
    – If v is smaller than the value of the root: insert v into the left sub-tree.
    – If v is larger than the value of the root: insert v into the right sub-tree.
     */
    if(isEmpty(bst)) {
        return makeTree(data, emptyTree(), emptyTree());
    } else if(data == root(bst)) {
        return bst;
    }



    //note here is a leak!!!
    //you can resolve this by next code
    //delete bst;
    if(data < root(bst)) {
        bst->setLeft(insert(data, left(bst)));
    } else if(root(bst) < data) {
        bst->setRight(insert(data, right(bst)));
    }
    return bst;
}

void show_bst(tree bst) {
    if(isEmpty(bst)) {
        return;
    }

    show_bst(left(bst));
    std::cout << root(bst) << " ";
    show_bst(right(bst));
}

tree isInBst(const Data& data, tree bst) {
    /*In order to search for a value v in a binary search tree t, proceed as follows. If t
    is empty, then v does not occur in t, and hence we stop with false. Otherwise,
    if v is equal to the root of t, then v does occur in t, and hence we stop returning
    true. If, on the other hand, v is smaller than the root, then, by definition of a
    binary search tree, it is enough to search the left sub-tree of t. Hence replace t
    by its left sub-tree and carry on in the same way. Similarly, if v is bigger than the
    root, replace t by its right sub-tree and carry on in the same way*/
    /*
     * this is recursive one
    if(isEmpty(bst)) {
        return emptyTree();
    }
    if(root(bst) == data) {
        return bst;
    }
    if(data < root(bst)) {
        return isInBst(data, left(bst));
    } else {
        return isInBst(data, right(bst));
    }*/
    while(true) {
        if(isEmpty(bst)) {
            return emptyTree();
        }
        if(root(bst) == data) {
            return bst;
        }
        if(data < root(bst)) {
            bst = left(bst);
        } else {
            bst = right(bst);
        }
    }
}



const Data& smallestNode(tree bst) {
    //NOTE: the precondition is that the bst is not a null tree
    while(not isEmpty(left(bst))) {
        bst = left(bst);
    }
    return bst->data;
}




tree removeSmallestNode(const tree& bst) {
    //NOTE: the precondition is that the bst is not a null tree
    if(isEmpty(left(bst))) {
        tree tmp = right(bst);
        delete bst;
        return tmp;
    }
    bst->setLeft(removeSmallestNode(left(bst)));
    return bst;
}
tree deleteNode(const Data& data, const tree& bst) {
    if(isEmpty(bst))  {
        std::cout << "wrong, the "<< data <<" is not in this tree" << std::endl;
        return bst;
    }

    if(data < root(bst)) {
        bst->setLeft(deleteNode(data, left(bst)));
        return bst;
    } else if(root(bst) < data) {
        bst->setRight(deleteNode(data, right(bst)));
        return bst;
    } else {
        if (isEmpty(left(bst))) {
            tree tmp = right(bst);
            delete bst;
            return tmp;
        } else if (isEmpty(right(bst))) {
            tree tmp = left(bst);
            delete bst;
            return tmp;
        } else {
            const Data data1 = smallestNode(right(bst));
            return makeTree(data1, left(bst), removeSmallestNode(right(bst)));
        }
    }
}
