// Areefa Samar - CT-25062
// Question 01 (Lab 04)

#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    char* arr;
    int capacity;
    int topIndex;
public:
    Stack(int size) {
        capacity = size;
        arr = new char[capacity];
        topIndex = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(char element) {
        if (topIndex == capacity - 1) {
            cout << "Stack overflow." << endl;
            return;
        }
        arr[++topIndex] = element;
    }

    char pop() {
        if (topIndex == -1) {
            cout << "Stack underflow." << endl;
            return '\0';
        }
        return arr[topIndex--];
    }

    bool isEmpty() const {
        return topIndex == -1;
    }
};

bool isPalindrome(string s) {
    Stack st(s.length());

    for (int i = 0; i < s.length(); i++) {
        st.push(s[i]);
    }

    for (int i = 0; i < s.length(); i++) {
        char top = st.pop();
        if (s[i] != top) {
            return false;
        }
    }

    return true;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    if (isPalindrome(s))
        cout << s << " is a palindrome." << endl;
    else
        cout << s << " is not a palindrome." << endl;

    return 0;
}