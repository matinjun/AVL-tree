//
// Created by L on 2019/11/1.
//

#ifndef MY_BINARY_TREE_1_0_DATA_H
#define MY_BINARY_TREE_1_0_DATA_H

#include <iostream>
//template <class type = int>
class Data {
public:
    int val;
    Data(int tmp):val(tmp) {}

public:

    // you need define comparison way
    // you need overload =, +, -, >, <, >=, <=
    friend std::ostream&operator<<(std::ostream& out, const Data& data) {
        out << data.val;
        return out;
    }

    friend bool operator<(const Data& a, const Data& b) {
        return a.val < b.val;
    }
    friend bool operator==(const Data& a, const Data& b) {
        return a.val == b.val;
    }
    friend bool operator>(const Data& a, const Data& b) {
        return a.val > b.val;
    }
    friend bool operator<=(const Data& a, const Data& b) {
        return a.val <= b.val;
    }
    friend bool operator>=(const Data& a, const Data& b) {
        return a.val >= b.val;
    }


};

#endif //MY_BINARY_TREE_1_0_DATA_H
