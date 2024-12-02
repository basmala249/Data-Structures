//
// Created by Lenovo on 12/2/2024.
//

#ifndef SKIPLIST_H
#define SKIPLIST_H
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll negINF = -1e9 , posINF = 1e9;
struct SkipNode {
    int key ;
    SkipNode* up = NULL;
    SkipNode* down = NULL;
    SkipNode* right = NULL;
    SkipNode* left = NULL;
    SkipNode(int val) {
        key = val;
    }
};

class SkipList {
    SkipNode* head = NULL;
    SkipNode* tail = NULL;
    bool tossCoin();
    void levelUP(vector<SkipNode*>& , SkipNode* );
    public:
    SkipList();
    // ~SkipList();
    void insert(int key);
    string search(int key);
    // bool del(int key);
    void print();

};

SkipList::SkipList() {
    head = new SkipNode(negINF);
    tail = new SkipNode(posINF);
    head->right = tail;
    tail->left = head;
}

void SkipList::insert(int key) {
    vector<SkipNode*> Randomized;
    SkipNode* temp = head;
    SkipNode* newNode = new SkipNode(key);
    while(true) {
        if(key > temp-> right ->key) {
            temp = temp->right;
        }
        else {
            if(temp->down == NULL) {
                newNode->right = temp->right;
                newNode->left = temp;
                temp -> right = newNode;
                break;
            }
            else {
                Randomized.push_back(temp);
                temp = temp->down;
            }
        }
    }
    levelUP(Randomized, newNode);
}

bool SkipList::tossCoin() {
        // Generate a random number (0 or 1)
        int result = rand() % 2; // 0 for Tail, 1 for Head
        return result;
}

void SkipList::levelUP(vector<SkipNode*>& nodes, SkipNode* newNode) {
    if(tossCoin()) {
        SkipNode* temp = new SkipNode(newNode->key);
        if(nodes.empty()) {
           SkipNode* newHead = new SkipNode(head->key);
           SkipNode* newTail = new SkipNode(tail->key);
           newHead->right = newTail;
           newTail->left = newHead;
           newHead->down = head;
           newTail->down = tail;
           head = newHead;
           tail = newTail;
           temp->right = head->right;
           temp->left = head;
           head->right = temp;
           temp -> down = newNode;
           newNode -> up = temp;
           return;
        }
        SkipNode* curr = nodes.back();
        nodes.pop_back();
        temp -> right = curr->right;
        temp -> left = curr;
        curr -> right = temp;
        temp -> down = newNode;
        newNode -> up = temp;
        levelUP(nodes, temp);
    }
}

void SkipList::print() {
    SkipNode* start = head; // Start at the topmost level
    while (start) {         // Traverse downwards through the levels
        SkipNode* temp = start;
        while (temp) {      // Traverse right through the current level
            cout << temp->key;
            if (temp->right) {
                cout << " -> ";
            }
            temp = temp->right;
        }
        cout << '\n';       // End of the current level
        start = start->down; // Move to the level below
    }
}

string SkipList::search(int key) {
    SkipNode* temp = head;
    
}


#endif //SKIPLIST_H
