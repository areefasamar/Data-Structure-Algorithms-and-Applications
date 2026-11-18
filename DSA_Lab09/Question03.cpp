// Areefa Samar - CT-25062
// Question 03 (Lab 09)

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
    TreeNode* search(int key) {
        return searchRec(root, key);
    }
    TreeNode* leastCommonAncestor(TreeNode* p, TreeNode* q) {
        return lcaRec(root, p, q);
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
    TreeNode* searchRec(TreeNode* node, int key) {
        if (node == NULL || node->val == key)
            return node;
        if (key < node->val)
            return searchRec(node->left, key);
        return searchRec(node->right, key);
    }
    TreeNode* lcaRec(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (node == NULL)
            return NULL;
        if (p->val < node->val && q->val < node->val)
            return lcaRec(node->left, p, q);
        if (p->val > node->val && q->val > node->val)
            return lcaRec(node->right, p, q);
        return node;
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
    TreeNode* p = bst.search(20);
    TreeNode* q = bst.search(40);
    TreeNode* ancestor = bst.leastCommonAncestor(p, q);
    cout << "Least common ancestor of 20 and 40: " << ancestor->val << endl;
    p = bst.search(20);
    q = bst.search(80);
    ancestor = bst.leastCommonAncestor(p, q);
    cout << "Least common ancestor of 20 and 80: " << ancestor->val << endl;
    p = bst.search(60);
    q = bst.search(70);
    ancestor = bst.leastCommonAncestor(p, q);
    cout << "Least common ancestor of 60 and 70: " << ancestor->val << endl;
}
