// Areefa Samar - CT-25062
// Question 04 (Lab 08)

#include <iostream>
#include <queue>
#include <string>
#include <vector>
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

int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) return i;
    }
    return -1;
}

Node* build(int preorder[], int inorder[], int inStart, int inEnd, int& preIndex) {
    if (inStart > inEnd) return nullptr;

    Node* node = new Node(preorder[preIndex]);
    preIndex++;

    int inIndex = findIndex(inorder, inStart, inEnd, node->data);

    node->left = build(preorder, inorder, inStart, inIndex - 1, preIndex);
    node->right = build(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return node;
}

Node* buildTree(int preorder[], int inorder[], int n) {
    int preIndex = 0;
    return build(preorder, inorder, 0, n - 1, preIndex);
}

void printLevelOrder(Node* root) {
    vector<string> result;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        if (current == nullptr) {
            result.push_back("null");
        } else {
            result.push_back(to_string(current->data));
            q.push(current->left);
            q.push(current->right);
        }
    }
    while (!result.empty() && result.back() == "null") {
        result.pop_back();
    }
    cout << "[";
    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i];
        if (i != (int)result.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};
    int n = sizeof(preorder) / sizeof(preorder[0]);

    Node* root = buildTree(preorder, inorder, n);

    cout << "Level Order Output: ";
    printLevelOrder(root);

    return 0;
}
