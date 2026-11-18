// Areefa Samar - CT-25062
// Question 04 (Lab 09)

#include <iostream>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(NULL), right(NULL) {}
};
class BinarySearchTree {
public:
    TreeNode* root;
    BinarySearchTree() : root(NULL) {}
    void insert(int key) {
        root = insertRec(root, key);
    }
    void inorder() {
        inorderRec(root);
        cout << endl;
    }
    int sum() {
        return sumRec(root);
    }
private:
    TreeNode* insertRec(TreeNode* node, int key) {
        if (node == NULL)
            return new TreeNode(key);
        if (key < node->val)
            node->left = insertRec(node->left, key);
        else if (key > node->val)
            node->right = insertRec(node->right, key);
        return node;
    }
    int sumRec(TreeNode* node) {
        if (node == NULL)
            return 0;
        return node->val + sumRec(node->left) + sumRec(node->right);
    }
    void inorderRec(TreeNode* root) {
        if (root != NULL) {
            inorderRec(root->left);
            cout << root->val << " ";
            inorderRec(root->right);
        }
    }
};
int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);
    cout << "Inorder traversal of the tree: ";
    bst.inorder();
    cout << "Sum of all nodes: " << bst.sum() << endl;
}
