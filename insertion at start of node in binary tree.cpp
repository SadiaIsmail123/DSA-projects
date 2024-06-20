#include <iostream>

using namespace std;

// Define the structure of a node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Function to insert a node at the start of the binary tree
void insertAtStart(TreeNode*& root, int value) {
    // Create a new node with the given value
    TreeNode* newNode = new TreeNode(value);

    // If the tree is empty, make the new node as the root
    if (root == NULL) {
        root = newNode;
    } else {
        // Find a node without a left child
        TreeNode* current = root;
        while (current->left != NULL || current->right != NULL) {
            if (current->left != NULL) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        // Insert the new node as the left child of the found node
        current->left = newNode;
    }
}

// Function to print the tree (inorder traversal)
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Binary Tree before insertion: ";
    inorderTraversal(root);
    cout << endl;

    // Inserting a node with value 0 at the start of the tree
    insertAtStart(root, 0);

    cout << "Binary Tree after insertion: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
