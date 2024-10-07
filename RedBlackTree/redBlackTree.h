//
// Created by Lenovo on 10/6/2024.
//

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include <stddef.h>

struct RBTNode {
    int data {};
    char color = 'R';
    RBTNode *left = NULL;
    RBTNode *right = NULL;
    RBTNode *parent = NULL;
    RBTNode() {}
    RBTNode(int data) : data(data) {}
};

class redBlackTree {
    RBTNode *root = NULL;
    void insert(RBTNode * node);
    void rotateLeft(RBTNode *node);
    void rotateRight(RBTNode *node);
    void postOrderTraversal(RBTNode *node);
    void rebalance(RBTNode *node);
    void deleteTree(RBTNode *node);
    public:
    redBlackTree();
    ~redBlackTree();
    void insert(int data);
    void print();
};



#endif //REDBLACKTREE_H
