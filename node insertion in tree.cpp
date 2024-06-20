#include <iostream>

using namespace std;


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

void insertAtLeaf(Node* root, int data) {
    
    if (root == NULL) {
        cout << "Tree is empty. Creating root node with data " << data << endl;
        root = new Node(data);
        return;
     return;
    }

    
    if (root->left == NULL && root->right == NULL) {
        root->left = new Node(data);
        return;
    }

    
    if (root->left != NULL) {
        insertAtLeaf(root->left, data);
    }
    if (root->right != NULL) {
        insertAtLeaf(root->right, data);
    }
}


void inorderTraversal(Node* root) {
    if (root != NULL) {
 inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Binary tree before insertion: ";
 inorderTraversal(root);
    cout << endl;

    // Inserting nodes at leaves
    insertAtLeaf(root, 6);
    insertAtLeaf(root, 7);
    insertAtLeaf(root, 8);

    cout << "Binary tree after insertion: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

