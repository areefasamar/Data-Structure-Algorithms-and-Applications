// Areefa Samar - CT-25062
// Question 01 (Lab 08)

#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->left == nullptr) {
                current->left = newNode;
                return;
            } else {
                q.push(current->left);
            }

            if (current->right == nullptr) {
                current->right = newNode;
                return;
            } else {
                q.push(current->right);
            }
        }
    }

    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }

    void preorder() {
        preorderTraversal(root);
        cout << endl;
    }

    void postorder() {
        postorderTraversal(root);
        cout << endl;
    }

    bool search(int value) {
        return searchNode(root, value);
    }

private:
    void inorderTraversal(Node* node) {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void preorderTraversal(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void postorderTraversal(Node* node) {
        if (node == nullptr) return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }

    bool searchNode(Node* node, int value) {
        if (node == nullptr) return false;
        if (node->data == value) return true;
        return searchNode(node->left, value) || searchNode(node->right, value);
    }
};

int main() {
    BinaryTree tree;

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);

    cout << "Inorder Traversal: ";
    tree.inorder();

    cout << "Preorder Traversal: ";
    tree.preorder();

    cout << "Postorder Traversal: ";
    tree.postorder();

    cout << "Search 5: " << (tree.search(5) ? "Found" : "Not Found") << endl;
    cout << "Search 10: " << (tree.search(10) ? "Found" : "Not Found") << endl;

    return 0;
}
