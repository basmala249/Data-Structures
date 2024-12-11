#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll negINF = -1e9, posINF = 1e9;
template <typename T>
struct SkipNode {
    T key;
    SkipNode<T>* up = NULL;
    SkipNode<T>* down = NULL;
    SkipNode<T>* right = NULL;
    SkipNode<T>* left = NULL;
    SkipNode(T val) {
        key = val;
    }
};
template <typename T>
class SkipList {
    SkipNode<T>* head = NULL;
    SkipNode<T>* tail = NULL;
    map <int, int> nodeCount;
    int Level = 0;
    bool tossCoin();
    void levelUP(vector<SkipNode<T>*>&, SkipNode<T>*, int);
public:
    SkipList();
    // ~SkipList();
    void insert(T key);
    string search(T key);
    void CleanUp();
    void remove(T key);
    void print();
    void inCrementLevel();
    void deCrementLevel();
};
template <typename T>
SkipList<T>::SkipList() {
    head = new SkipNode<T>(negINF);
    tail = new SkipNode<T>(posINF);
    head->right = tail;
    tail->left = head;
    Level = 1;
    nodeCount[Level] += 2;
}
template <typename T>
void SkipList<T>::insert(T key) {
    vector<SkipNode<T>*> Randomized;
    SkipNode<T>* temp = head;
    int l = Level;
    SkipNode<T>* newNode = new SkipNode<T>(key);
    while (true) {
        if (key > temp->right->key) {
            temp = temp->right;
        }
        else {
            if (temp->down == NULL) {
                nodeCount[l]++;
                temp->right->left = newNode;
                newNode->right = temp->right;
                newNode->left = temp;
                temp->right = newNode;
                break;
            }
            else {
                l--;
                Randomized.push_back(temp);
                temp = temp->down;
            }
        }
    }
    levelUP(Randomized, newNode, l + 1);
}
template <typename T>
bool SkipList<T>::tossCoin() {
    // Generate a random number (0 or 1)
    int result = rand() % 2; // 0 for Tail, 1 for Head
    return result;
}
template <typename T>
void SkipList<T>::levelUP(vector<SkipNode<T>*>& nodes, SkipNode<T>* newNode, int l) {
    if (tossCoin()) {
        SkipNode<T>* temp = new SkipNode<T>(newNode->key);
        if (nodes.empty()) {
            inCrementLevel();
            nodeCount[l] += 3;
            SkipNode<T>* newHead = new SkipNode<T>(head->key);
            SkipNode<T>* newTail = new SkipNode<T>(tail->key);
            newHead->right = newTail;
            newTail->left = newHead;
            newHead->down = head;
            newTail->down = tail;
            head->up = newHead;
            tail->up = newTail;
            head = newHead;
            tail = newTail;
            tail->left = temp;
            temp->right = head->right;
            temp->left = head;
            head->right = temp;
            temp->down = newNode;
            newNode->up = temp;
            return;
        }
        SkipNode<T>* curr = nodes.back();
        nodes.pop_back();
        curr->right->left = temp;
        temp->right = curr->right;
        temp->left = curr;
        curr->right = temp;
        temp->down = newNode;
        newNode->up = temp;
        nodeCount[l]++;
        levelUP(nodes, temp, l + 1);
    }
}
template <typename T>
void SkipList<T>::print() {
    SkipNode<T>* start = head; // Start at the topmost level
    while (start) {         // Traverse downwards through the levels
        SkipNode<T>* temp = start;
        while (temp != NULL) {      // Traverse right through the current level
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
template <typename T>
string SkipList<T>::search(T key) {
    SkipNode<T>* temp = head;
    while (temp != NULL) {
        if (temp->key == key) {
            return "Found\n";
        }
        else if (temp->right->key > key) {
            temp = temp->down;
        }
        else {
            temp = temp->right;
        }
    }
    return "Not Found\n";
}
template <typename T>
void SkipList<T>::remove(T key) {
    SkipNode<T>* temp = head;
    bool found = false;
    int cur = Level;
    // Traverse the skip list to find the node with the key
    while (temp != NULL) {
        if (temp->right->key == key) {
            temp = temp->right;
            found = true;
            break;
        }
        else if (temp->right == NULL || temp->right->key > key) {
            temp = temp->down; // Move down a level
            cur--;
        }
        else {
            temp = temp->right; // Move to the next node on the same level
        }
    }
    // Remove the node from all levels
    while (temp != NULL) {
        SkipNode<T>* down = temp->down; // Save the pointer to the node below
        // Unlink the current node
        if (temp->left) {
            temp->left->right = temp->right;
        }
        if (temp->right) {
            temp->right->left = temp->left;
        }
        if (down) {
            down->up = NULL;
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
template <typename T>
void SkipList<T>::inCrementLevel() {
    Level++;
}
template <typename T>
void SkipList<T>::deCrementLevel() {
    Level--;
}
template <typename T>
void SkipList<T>::CleanUp() {
    int cur = Level;
    bool foundToBeDeleted = true;
    while (cur != 1 && foundToBeDeleted) {
        if (nodeCount[cur] == 2 || nodeCount[cur] == nodeCount[cur - 1]) {
            deCrementLevel();
            SkipNode<T>* temp = head;
            head = head->down;
            tail = tail->down;
            while (temp != NULL) {
                temp->down->up = NULL;
                SkipNode<T>* t = temp;
                temp = temp->right;
                delete t;
            }
            cur--;
        }
        else {
            foundToBeDeleted = false;
        }
    }
}
