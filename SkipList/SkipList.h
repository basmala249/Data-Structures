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
    map <int, int> nodeCount;
    int Level = 0;
    bool tossCoin();
    void levelUP(vector<SkipNode*>& , SkipNode* , int);
    public:
    SkipList();
    // ~SkipList();
    void insert(int key);
    string search(int key);
    void CleanUp();
    void remove(int key);
    void print();
    void inCrementLevel();

    void deCrementLevel();
};

SkipList::SkipList() {
    head = new SkipNode(negINF);
    tail = new SkipNode(posINF);
    head->right = tail;
    tail->left = head;
    Level = 1;
    nodeCount[Level] += 2;
}

void SkipList::insert(int key) {
    vector<SkipNode*> Randomized;
    SkipNode* temp = head;
    int l = Level;
    SkipNode* newNode = new SkipNode(key);
    while(true) {
        if(key > temp-> right ->key) {
            temp = temp->right;
        }
        else {
            if(temp->down == NULL) {
                nodeCount[l]++;
                temp -> right -> left = newNode ;
                newNode->right = temp->right;
                newNode->left = temp;
                temp -> right = newNode;
                break;
            }
            else {
                l--;
                Randomized.push_back(temp);
                temp = temp->down;
            }
        }
    }
    levelUP(Randomized, newNode , l + 1);
}

bool SkipList::tossCoin() {
        // Generate a random number (0 or 1)
        int result = rand() % 2; // 0 for Tail, 1 for Head
        return result;
}

void SkipList::levelUP(vector<SkipNode*>& nodes, SkipNode* newNode , int l) {
    if(tossCoin()) {
        SkipNode* temp = new SkipNode(newNode->key);
        if(nodes.empty()) {
           inCrementLevel();
           nodeCount[l] += 3;
           SkipNode* newHead = new SkipNode(head->key);
           SkipNode* newTail = new SkipNode(tail->key);
           newHead->right = newTail;
           newTail->left = newHead;
           newHead->down = head;
           newTail->down = tail;
           head -> up = newHead;
           tail -> up = newTail;
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
        nodeCount[l]++;
        levelUP(nodes, temp , l + 1);
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
    int cur = Level;
    // Traverse the skip list to find the node with the key
    while (temp != NULL) {
        if (temp->right->key == key) {
            temp = temp->right;
            found = true;
            break;
        } else if (temp->right == NULL || temp->right->key > key) {
            temp = temp->down; // Move down a level
            cur--;
        } else {
            temp = temp->right; // Move to the next node on the same level
        }
    }
    // Remove the node from all levels
    while (temp != NULL) {
        SkipNode* down = temp->down; // Save the pointer to the node below
        // Unlink the current node
        if (temp->left) {
            temp->left->right = temp->right;
        }
        if (temp->right) {
            temp->right->left = temp->left;
        }
        if(down) {
            down -> up = NULL;
        }
        nodeCount[cur]--;
        if (nodeCount[cur] == 0) {
            nodeCount.erase(cur);
        }
        // Delete the current node
        delete temp;
        temp = down; // Move down a level
        cur--;
    }
    CleanUp();
}

void SkipList::inCrementLevel() {
    Level++;
}
void SkipList::deCrementLevel() {
    Level--;
}
void SkipList::CleanUp() {
    int cur = Level;
    bool foundToBeDeleted = true;
    while(cur != 1 && foundToBeDeleted) {
        if(nodeCount[cur] == 2 || nodeCount[cur] == nodeCount[cur - 1]) {
            deCrementLevel();
            SkipNode* temp = head ;
            head = head->down;
            tail = tail->down;
            while(temp != NULL) {
                temp -> down -> up = NULL;
                SkipNode* t = temp;
                temp = temp -> right;
                delete t;
            }
            cur--;
        }
        else {
            foundToBeDeleted = false;
        }
    }
}




#endif // SKIPLIST_H
