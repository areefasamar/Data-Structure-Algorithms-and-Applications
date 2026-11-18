// Areefa Samar - CT-25062
// Question 02 (Lab 09)

#include <iostream>
#include <string>
using namespace std;
class EmployeeNode {
public:
    int id;
    string name;
    string department;
    EmployeeNode* left;
    EmployeeNode* right;
    EmployeeNode(int i, string n, string d) : id(i), name(n), department(d), left(NULL), right(NULL) {}
};
class EmployeeBST {
public:
    EmployeeNode* root;
    EmployeeBST() : root(NULL) {}
    void insert(int id, string name, string department) {
        if (searchNode(root, id) != NULL) {
            cout << "Employee with ID " << id << " already exists. Insertion skipped\n";
            return;
        }
        root = insertRec(root, id, name, department);
    }
    string search(int id) {
        if (root == NULL) {
            cout << "Tree is empty\n";
            return "";
        }
        EmployeeNode* node = searchNode(root, id);
        if (node == NULL) {
            cout << "Employee with ID " << id << " not found\n";
            return "";
        }
        return node->name + ", " + node->department;
    }
    void deleteNode(int id) {
        if (root == NULL) {
            cout << "Tree is empty. Nothing to delete\n";
            return;
        }
        if (searchNode(root, id) == NULL) {
            cout << "Employee with ID " << id << " does not exist. Deletion skipped\n";
            return;
        }
        root = deleteRec(root, id);
        cout << "Employee with ID " << id << " deleted\n";
    }
    void inOrderTraversal() {
        if (root == NULL) {
            cout << "Tree is empty\n";
            return;
        }
        inOrderRec(root);
    }
    string findMin() {
        if (root == NULL) {
            cout << "Tree is empty\n";
            return "";
        }
        EmployeeNode* node = minValueNode(root);
        return node->name + ", " + node->department;
    }
    string findMax() {
        if (root == NULL) {
            cout << "Tree is empty\n";
            return "";
        }
        EmployeeNode* current = root;
        while (current->right != NULL)
            current = current->right;
        return current->name + ", " + current->department;
    }
private:
    EmployeeNode* insertRec(EmployeeNode* node, int id, string name, string department) {
        if (node == NULL)
            return new EmployeeNode(id, name, department);
        if (id < node->id)
            node->left = insertRec(node->left, id, name, department);
        else if (id > node->id)
            node->right = insertRec(node->right, id, name, department);
        return node;
    }
    EmployeeNode* searchNode(EmployeeNode* node, int id) {
        if (node == NULL || node->id == id)
            return node;
        if (id < node->id)
            return searchNode(node->left, id);
        return searchNode(node->right, id);
    }
    EmployeeNode* deleteRec(EmployeeNode* node, int id) {
        if (node == NULL)
            return node;
        if (id < node->id)
            node->left = deleteRec(node->left, id);
        else if (id > node->id)
            node->right = deleteRec(node->right, id);
        else {
            if (node->left == NULL) {
                EmployeeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                EmployeeNode* temp = node->left;
                delete node;
                return temp;
            }
            EmployeeNode* temp = minValueNode(node->right);
            node->id = temp->id;
            node->name = temp->name;
            node->department = temp->department;
            node->right = deleteRec(node->right, temp->id);
        }
        return node;
    }
    EmployeeNode* minValueNode(EmployeeNode* node) {
        EmployeeNode* current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }
    void inOrderRec(EmployeeNode* node) {
        if (node != NULL) {
            inOrderRec(node->left);
            cout << "ID: " << node->id << ", Name: " << node->name << ", Department: " << node->department << endl;
            inOrderRec(node->right);
        }
    }
};
int main() {
    EmployeeBST bst;
    cout << "Search on empty tree: ";
    bst.search(10);
    bst.deleteNode(10);
    bst.inOrderTraversal();
    bst.insert(50, "Ali Khan", "HR");
    bst.insert(30, "Sara Ahmed", "Finance");
    bst.insert(20, "Usman Raza", "IT");
    bst.insert(40, "Hina Malik", "Marketing");
    bst.insert(70, "Bilal Sheikh", "Sales");
    bst.insert(60, "Ayesha Noor", "IT");
    bst.insert(80, "Zain Ali", "Admin");
    bst.insert(30, "Duplicate Person", "HR");
    cout << "All employees in ascending order of ID:\n";
    bst.inOrderTraversal();
    string result = bst.search(40);
    if (result != "")
        cout << "Employee 40: " << result << endl;
    bst.search(99);
    cout << "Smallest ID: " << bst.findMin() << endl;
    cout << "Largest ID: " << bst.findMax() << endl;
    cout << "Delete 20 (no children)\n";
    bst.deleteNode(20);
    cout << "Delete 30 (one child)\n";
    bst.deleteNode(30);
    cout << "Delete 50 (two children)\n";
    bst.deleteNode(50);
    bst.deleteNode(99);
    cout << "All employees after deletions:\n";
    bst.inOrderTraversal();
}
