
#include <iostream>
using namespace std;
template <typename T, int Order>
struct BTreeNode {
    BTreeNode<T, Order>* Children[Order + 1]; // Array of pointers to children nodes
    BTreeNode<T, Order>* parent = nullptr; // Parent node pointer
    T keys[Order]; // Array to store keys
    int indx; // Number of keys in the node
    bool isLeaf = false; // Flag to check if the node is a leaf
    BTreeNode() {
        indx = 0;
        isLeaf = false;
        for (int i = 0; i <= Order; ++i) {
            Children[i] = nullptr; // Initialize all child pointers to nullptr
        }
    }
};

template <typename T, int Order>
class BTree {
private:
    BTreeNode<T, Order>* root;
    int MaxKey;               // Maximum number of keys in a node
    void Print(BTreeNode<T, Order>* root, int Count);
    void insertHelper(BTreeNode<T, Order>* root, T val);
    void Split(BTreeNode<T, Order>* root);
    void FillKeys(BTreeNode<T, Order>* Parent, BTreeNode<T, Order>* L, BTreeNode<T, Order>* R, int mid);
    void FillChildren(BTreeNode<T, Order>* Parent, BTreeNode<T, Order>* L, BTreeNode<T, Order>* R, int mid);
public:
    BTree();                  // Default constructor
    void Insert(T key);       // Insert a key
    void Print();             // Print the tree
};

template <typename T, int Order>
BTree<T, Order>::BTree() {
    root = new BTreeNode<T, Order>();
    MaxKey = Order - 1;
    root->isLeaf = true;
}

template<typename  T, int Order>
void BTree<T, Order>::Insert(T val) {
    insertHelper(root, val);
}
template <typename T, int Order>
void BTree<T, Order>::Split(BTreeNode<T, Order>* p) {
    int mid = p->indx / 2;
    BTreeNode<T, Order>* LChild = new BTreeNode<T, Order>();
    BTreeNode<T, Order>* RChild = new BTreeNode<T, Order>();
    BTreeNode<T, Order>* temp = nullptr;
    bool newRoot = false;

    if (p->parent) {
        temp = p->parent;
    }
    else {
        temp = new BTreeNode<T, Order>();
        newRoot = true;
    }

    T val = p->keys[mid];

    // Insert mid value into parent node
    int i = 0;
    while (i < temp->indx && val > temp->keys[i]) {
        ++i;
    }
    for (int j = temp->indx; j > i; --j) {
        temp->keys[j] = temp->keys[j - 1];
        temp->Children[j + 1] = temp->Children[j];
    }
    FillKeys(p, LChild, RChild, mid);
    temp->keys[i] = val;
    temp->Children[i] = LChild;
    temp->Children[i + 1] = RChild;
    temp->indx++;

    // Distribute keys and children

    FillChildren(p, LChild, RChild, mid);

    // Set parent pointers
    LChild->parent = temp;
    RChild->parent = temp;
    LChild->isLeaf = p->isLeaf;
    RChild->isLeaf = p->isLeaf;

    delete p;


    // Recursively split the parent if necessary
    if (temp->indx == Order) {
        Split(temp);
    }
    if (newRoot) {
        root = temp;
    }

}


template <typename T, int Order>
void BTree<T, Order>::FillChildren(BTreeNode<T, Order>* Parent, BTreeNode<T, Order>* L, BTreeNode<T, Order>* R, int mid) {
    if (Parent->isLeaf) {
        return; // No children to transfer if the node is a leaf
    }

    // Transfer left children
    for (int i = 0; i <= mid; i++) {
        L->Children[i] = Parent->Children[i];
        if (L->Children[i] != nullptr) {
            L->Children[i]->parent = L; // Update parent pointer
        }
    }

    // Transfer right children
    int j = 0;
    for (int i = mid + 1; i <= Order; i++) {
        R->Children[j] = Parent->Children[i];
        if (R->Children[j] != nullptr) {
            R->Children[j]->parent = R; // Update parent pointer
        }
        j++;
    }

    // Clear transferred children in the parent
    for (int i = 0; i <= Order; i++) {
        Parent->Children[i] = nullptr;
    }
}


template <typename T, int Order>
void BTree<T, Order>::FillKeys(BTreeNode<T, Order>* Parent, BTreeNode<T, Order>* L, BTreeNode<T, Order>* R, int mid) {
    for (int i = 0; i < mid; i++) {
        L->keys[L->indx] = Parent->keys[i];
        (L->indx)++;
    }
    for (int i = mid + 1; i < Parent->indx; i++) {
        R->keys[R->indx] = Parent->keys[i];
        (R->indx)++;
    }
}

template <typename T, int Order>
void BTree<T, Order>::insertHelper(BTreeNode<T, Order>* p, T val) {
    if (p->isLeaf) {
        int i = 0;
        while (i < p->indx) {
            if (val < p->keys[i]) {
                break;
            }
            i++;
        }

        for (int j = (p->indx); j > i; j--) {
            p->keys[j] = p->keys[j - 1];
        }
        (p->indx)++;
        p->keys[i] = val;

        // Split if the node is full
        if (p->indx == Order) {
            Split(p);
        }
        return;
    }

    // Find the child to traverse
    int child = -1;
    for (int i = 0; i < p->indx; i++) {
        if (val < p->keys[i]) {
            child = i;
            break;
        }
    }
    if (child == -1) {
        child = p->indx;
    }

    insertHelper(p->Children[child], val);
}


template<typename  T, int Order>
void BTree<T, Order> ::Print() {
    Print(root, 0);
}


template <typename T, int Order>
void BTree<T, Order>::Print(BTreeNode<T, Order>* p, int cnt) {
    if (p == nullptr) {
        return;
    }

    for (int i = 0; i < cnt; ++i) {
        cout << " ";
    }
    for (int i = 0; i < p->indx; ++i) {
        cout << p->keys[i] << " ";
    }
    cout << '\n';

    for (int i = 0; i <= p->indx; ++i) {
        if (p->Children[i]) { // Avoid null pointers
            Print(p->Children[i], cnt + 2);
        }
    }
}
