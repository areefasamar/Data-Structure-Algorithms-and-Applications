// Areefa Samar - CT-25062
// Question 02 (Lab 08)

#include <iostream>
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

bool isMirror(Node* a, Node* b) {
    if (a == nullptr && b == nullptr) return true;
    if (a == nullptr || b == nullptr) return false;
    return a->data == b->data && isMirror(a->left, b->right) && isMirror(a->right, b->left);
}

bool isSymmetric(Node* root) {
    if (root == nullptr) return true;
    return isMirror(root->left, root->right);
}

int main() {
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(2);
    root1->left->left = new Node(3);
    root1->left->right = new Node(4);
    root1->right->left = new Node(4);
    root1->right->right = new Node(3);

    cout << "Tree 1 Output: " << (isSymmetric(root1) ? "true" : "false") << endl;

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(2);
    root2->left->right = new Node(3);
    root2->right->right = new Node(3);

    cout << "Tree 2 Output: " << (isSymmetric(root2) ? "true" : "false") << endl;

    return 0;
}
