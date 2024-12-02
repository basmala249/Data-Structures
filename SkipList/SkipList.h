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
    void remove(int key);
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
                temp -> right -> left = newNode ;
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
           tail -> left = temp;
           temp->right = head->right;
           temp->left = head;
           head->right = temp;
           temp -> down = newNode;
           newNode -> up = temp;
           return;
        }
        SkipNode* curr = nodes.back();
        nodes.pop_back();
        curr -> right -> left = temp ;
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
        while (temp!= NULL ) {      // Traverse right through the current level
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
    while(temp != NULL) {
        if(temp->key == key) {
            return "Found\n";
        }
        else if(temp-> right -> key > key) {
            temp = temp->down;
        }
        else {
            temp = temp->right;
        }
    }
    return "Not Found\n";
}

void SkipList::remove(int key) {
    SkipNode* temp = head;
    bool found = false;

    // Traverse the skip list to find the node with the key
    while (temp != NULL) {
        if (temp->right->key == key) {
            temp = temp->right;
            found = true;
            break;
        } else if (temp->right == NULL || temp->right->key > key) {
            temp = temp->down; // Move down a level
        } else {
            temp = temp->right; // Move to the next node on the same level
        }
    }
    cout << temp->left->key<<endl;
    // Remove the node from all levels
    while (temp != NULL) {
        SkipNode* down = temp->down; // Save the pointer to the node below
        // Unlink the current node
        if (temp->left) {
            //cout << temp->left->key<<endl;
            temp->left->right = temp->right;
        }
        if (temp->right) {
            temp->right->left = temp->left;
        }
        // Delete the current node
        delete temp;
        //print();
        temp = down; // Move down a level
    }
}
int main(){
    SkipList s;
    s.insert(100);
    s.insert(50);
    s.insert(2);
    s.insert(4);
    s.insert(1);
    s.insert(5);
    s.insert(32);
    s.insert(35);
    s.print() ;
}
#endif //SKIPLIST_H
