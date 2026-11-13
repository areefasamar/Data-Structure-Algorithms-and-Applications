// Areefa Samar - CT-25062
// Question 05 (Lab 08)

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

void robHelper(Node* node, int result[2]) {
    if (node == nullptr) {
        result[0] = 0;
        result[1] = 0;
        return;
    }

    int leftResult[2];
    int rightResult[2];
    robHelper(node->left, leftResult);
    robHelper(node->right, rightResult);

    result[0] = node->data + leftResult[1] + rightResult[1];

    int bestLeft = leftResult[0] > leftResult[1] ? leftResult[0] : leftResult[1];
    int bestRight = rightResult[0] > rightResult[1] ? rightResult[0] : rightResult[1];
    result[1] = bestLeft + bestRight;
}

int rob(Node* root) {
    int result[2];
    robHelper(root, result);
    return result[0] > result[1] ? result[0] : result[1];
}

int main() {
    Node* root1 = new Node(3);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->right = new Node(3);
    root1->right->right = new Node(1);

    cout << "Example 1 Output: " << rob(root1) << endl;

    Node* root2 = new Node(3);
    root2->left = new Node(4);
    root2->right = new Node(5);
    root2->left->left = new Node(1);
    root2->left->right = new Node(3);
    root2->right->right = new Node(1);

    cout << "Example 2 Output: " << rob(root2) << endl;

    return 0;
}
