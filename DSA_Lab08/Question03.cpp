// Areefa Samar - CT-25062
// Question 03 (Lab 08)

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

int checkHeight(Node* node) {
    if (node == nullptr) return 0;

    int leftHeight = checkHeight(node->left);
    if (leftHeight == -1) return -1;

    int rightHeight = checkHeight(node->right);
    if (rightHeight == -1) return -1;

    int difference = leftHeight - rightHeight;
    if (difference > 1 || difference < -1) return -1;

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isBalanced(Node* root) {
    return checkHeight(root) != -1;
}

int main() {
    Node* root1 = new Node(3);
    root1->left = new Node(9);
    root1->right = new Node(20);
    root1->right->left = new Node(15);
    root1->right->right = new Node(7);

    cout << "Tree 1 Output: " << (isBalanced(root1) ? "true" : "false") << endl;

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(2);
    root2->left->left = new Node(3);
    root2->left->right = new Node(3);
    root2->left->left->left = new Node(4);
    root2->left->left->right = new Node(4);

    cout << "Tree 2 Output: " << (isBalanced(root2) ? "true" : "false") << endl;

    return 0;
}
