#include "redBlackTree.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

redBlackTree::redBlackTree() {
    root = NULL;
}

void redBlackTree::insert(int key) {
    RBTNode *newNode = new RBTNode(key);
    newNode->parent = NULL;
    insert(newNode);
}

void redBlackTree::insert(RBTNode *node) {
    RBTNode *parent = NULL;
    RBTNode *current = root;
    while (current != NULL) {
        parent = current;
        if (node->data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    node->parent = parent;
    if (root == NULL) {
        root = node;
        root->color = 'B';
    } else {
        if (node->data < parent->data) {
            parent->left = node;
        } else {
            parent->right = node;
        }
        if (parent->color == 'R') {
            rebalance(node);
        }
    }
}

void redBlackTree::print() {
    postOrderTraversal(root);
    cout << '\n';
}

void redBlackTree::postOrderTraversal(RBTNode *node) {
    if (node == NULL) return;
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout << node->data << " " << node->color << " ";
}

redBlackTree::~redBlackTree() {
    deleteTree(root);
    root = NULL;
}

void redBlackTree::deleteTree(RBTNode *node) {
    if (node != NULL) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void redBlackTree::rebalance(RBTNode *node) {
    RBTNode *parent = node->parent;
    RBTNode *grandParent = parent ? parent->parent : NULL;
    RBTNode *uncle;
    while (node and node->color == 'R' and parent != NULL && grandParent != NULL && parent->color == 'R') {
        if (parent == grandParent->left) {
            uncle = grandParent->right;
        } else {
            uncle = grandParent->left;
        }
        if (uncle != NULL && uncle->color == 'R') {
            uncle->color = 'B';
            grandParent->color = 'R';
            parent->color = 'B';
            node = grandParent;
            parent = node -> parent;
            grandParent = parent ? parent->parent : NULL;
        } else {
            if (parent->right == node) {
                if (grandParent->right == parent) {
                    grandParent->color = 'R';
                    parent->color = 'B';
                    rotateLeft(grandParent);
                } else {
                    node->color = 'B';
                    parent->color = 'R';
                    grandParent->color = 'R';
                    rotateLeft(parent);
                    rotateRight(grandParent);
                }
            } else {
                if (grandParent->left == parent) {
                    grandParent->color = 'R';
                    parent->color = 'B';
                    rotateRight(grandParent);
                } else {
                    node->color = 'B';
                    parent->color = 'R';
                    grandParent->color = 'R';
                    rotateRight(parent);
                    rotateLeft(grandParent);
                }
            }
        }

    }
    root->color = 'B';
}

void redBlackTree::rotateLeft(RBTNode *node) {
    RBTNode *child = node->right;
    node->right = child->left;
    if (child->left != NULL) child->left->parent = node;
    child->parent = node->parent;
    if (node->parent == NULL) {
        root = child;
    } else if (node == node->parent->left) {
        node->parent->left = child;
    } else {
        node->parent->right = child;
    }
    child->left = node;
    node->parent = child;
}

void redBlackTree::rotateRight(RBTNode *node) {
    RBTNode *child = node->left;
    node->left = child->right;
    if (child->right != NULL) child->right->parent = node;
    child->parent = node->parent;
    if (node->parent == NULL) {
        root = child;
    } else if (node == node->parent->right) {
        node->parent->right = child;
    } else {
        node->parent->left = child;
    }
    child->right = node;
    node->parent = child;
}
