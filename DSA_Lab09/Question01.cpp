// Areefa Samar - CT-25062
// Question 01 (Lab 09)

#include <iostream>
#include <stack>
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
    void deleteNode(int key) {
        root = deleteRec(root, key);
    }
    void inorder() {
        inorderRec(root);
        cout << endl;
    }
    void preorder() {
        if (root == NULL)
            return;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* current = s.top();
            s.pop();
            cout << current->val << " ";
            if (current->right != NULL)
                s.push(current->right);
            if (current->left != NULL)
                s.push(current->left);
        }
        cout << endl;
    }
    void postorder() {
        if (root == NULL)
            return;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while (!s1.empty()) {
            TreeNode* current = s1.top();
            s1.pop();
            s2.push(current);
            if (current->left != NULL)
                s1.push(current->left);
            if (current->right != NULL)
                s1.push(current->right);
        }
        while (!s2.empty()) {
            cout << s2.top()->val << " ";
            s2.pop();
        }
        cout << endl;
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
    TreeNode* deleteRec(TreeNode* node, int key) {
        if (node == NULL)
            return node;
        if (key < node->val)
            node->left = deleteRec(node->left, key);
        else if (key > node->val)
            node->right = deleteRec(node->right, key);
        else {
            if (node->left == NULL) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = minValueNode(node->right);
            node->val = temp->val;
            node->right = deleteRec(node->right, temp->val);
        }
        return node;
    }
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
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
    cout << "Preorder traversal of the tree: ";
    bst.preorder();
    cout << "Postorder traversal of the tree: ";
    bst.postorder();
    cout << "Delete 20\n";
    bst.deleteNode(20);
    cout << "Preorder traversal of the tree after deleting 20: ";
    bst.preorder();
    cout << "Postorder traversal of the tree after deleting 20: ";
    bst.postorder();
}
