//
// Created by Lenovo on 10/6/2024.
//

#include "redBlackTree.h"
#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

redBlackTree::redBlackTree() {
    root = NULL;
}

void redBlackTree::insert(int key) {
    insert(root, NULL, key);
}

void redBlackTree::insert(RBTNode *node, RBTNode *parent, int key) {
    if (node == NULL) {
        RBTNode *newNode = new RBTNode(key);
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = parent;

        if (root == NULL) {
            root = newNode;
            newNode->color = 'B';
        } else {
            newNode->color = 'R';
            if (parent->data < key) {
                parent->right = newNode;
            } else {
                parent->left = newNode;
            }
            if (parent->color == 'R') {
                rebalance(parent, newNode->data);
            }
        }
        return;
    }
    if (key > node->data) {
        insert(node->right, node, key);
    } else if (key < node->data) {
        insert(node->left, node, key);
    }
}
void redBlackTree::rebalance(RBTNode *parent, int val) {
    if(parent -> color == 'B') return;
    if (root == parent or parent -> parent == NULL) { 
        return;
    }
    RBTNode *grandparent = parent->parent;
    RBTNode *uncle = (parent == grandparent->left) ? grandparent->right : grandparent->left;

    // Case 1: Parent and uncle are both red
    if (uncle != NULL && uncle->color == 'R') {
        parent->color = 'B';
        uncle->color = 'B';
        grandparent->color = 'R';
        rebalance(parent -> parent, parent->data);
    } else {
        // Case 2: Uncle is black or NULL

        // Left-Left case
        if (parent == grandparent->left && val < parent->data) {
            parent->color = 'B';
            grandparent->color = 'R';
            rotateRight(grandparent);
        }
        // Right-Right case
        else if (parent == grandparent->right && val > parent->data) {
            parent->color = 'B';
            grandparent->color = 'R';
            rotateLeft(grandparent);
        }
        // Left-Right case
        else if (parent == grandparent->left && val > parent->data) {
            parent -> right -> color = 'B';
            grandparent -> color = 'R';
            rotateLeft(parent);
            rotateRight(grandparent);
        }
        // Right-Left case
        else if (parent == grandparent->right && val < parent->data) {
            parent -> left -> color = 'B';
            grandparent -> color = 'R';
            rotateRight(parent);
            rotateLeft(grandparent);
        }
    }

    root->color = 'B'; // Ensure the root is always black
}


void redBlackTree::print() {
    postOrderTraversal(root);
    cout << '\n';
}

void redBlackTree::postOrderTraversal(RBTNode *node) {
    if (node == NULL)
        return;
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout << node->data << " " << node->color << endl;
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

void redBlackTree::rotateRight(RBTNode *parent) {
    RBTNode *child = parent->left;
    if (parent->parent == NULL) {
        root = child;
        child->parent = NULL;
    } else {
        child->parent = parent->parent;
        if (parent->parent->right == parent)
            parent->parent->right = child;
        else
            parent->parent->left = child;
    }
    parent->left = child->right;
    if (child->right != NULL) {
        child->right->parent = parent;
    }
    parent->parent = child;
    child->right = parent;
}

void redBlackTree::rotateLeft(RBTNode *parent) {
    RBTNode *child = parent->right;
    if (parent->parent == NULL) {
        root = child;
        child->parent = NULL;
    } else {
        child->parent = parent->parent;
        if (parent->parent->left == parent)
            parent->parent->left = child;
        else
            parent->parent->right = child;
    }
    parent->right = child->left;
    if (child->left != NULL) {
        child->left->parent = parent;
    }
    parent->parent = child;
    child->left = parent;
}