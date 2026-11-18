// Areefa Samar - CT-25062
// Question 05 (Lab 09)

#include <iostream>
#include <climits>
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
    int minDifference() {
        int minDiff = INT_MAX;
        TreeNode* prev = NULL;
        minDiffRec(root, prev, minDiff);
        return minDiff;
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
    void minDiffRec(TreeNode* node, TreeNode*& prev, int& minDiff) {
        if (node == NULL)
            return;
        minDiffRec(node->left, prev, minDiff);
        if (prev != NULL && node->val - prev->val < minDiff)
            minDiff = node->val - prev->val;
        prev = node;
        minDiffRec(node->right, prev, minDiff);
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
    bst.insert(4);
    bst.insert(2);
    bst.insert(6);
    bst.insert(1);
    bst.insert(3);
    cout << "Inorder traversal of the tree: ";
    bst.inorder();
    cout << "Minimum difference between any two nodes: " << bst.minDifference() << endl;
}
