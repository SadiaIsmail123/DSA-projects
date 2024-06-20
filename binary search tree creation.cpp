#include <iostream>
struct Node {
 int data;
 Node* left;
 Node* right;
};
int main() {
 // Create nodes
 Node* root = new Node();
 Node* leftChild = new Node();
 Node* rightChild = new Node();
 // Assign data to nodes
 root->data = 1;
 leftChild->data = 2;
 rightChild->data = 3;
 // Link nodes to form a tree
 root->left = leftChild;
 root->right = rightChild;
 leftChild->left = NULL;
 leftChild->right = NULL;
 rightChild->left = NULL;
 rightChild->right = NULL;
 // Traverse the tree and print the data
 std::cout << "Root: " << root->data << std::endl;
 std::cout << "Left Child: " << root->left->data << std::endl;
 std::cout << "Right Child: " << root->right->data << std::endl;
 // Delete nodes to avoid memory leaks
 delete root;
 delete leftChild;
 delete rightChild;
 return 0;
}
