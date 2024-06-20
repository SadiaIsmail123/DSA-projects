#include <iostream>

using namespace std;

// Node structure for binary search tree
struct Node {
    int data;
    Node* left;
    Node* right;
    
    // Constructor
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to insert a node into a binary search tree
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    
    return root;
}

// Function to perform inorder traversal of binary search tree
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;

    // Inserting elements into the binary search tree
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 9);

    // Printing elements of the binary search tree in sorted order
    cout << "Inorder Traversal of BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
} 

