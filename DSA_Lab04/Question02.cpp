// Areefa Samar - CT-25062
// Question 02 (Lab 04)

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

    void pop() {
        if (topIndex == -1) {
            return; 
        }
        topIndex--;
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    string getResult() const {
        string result = "";
        for (int i = 0; i <= topIndex; i++) {
            result += arr[i];
        }
        return result;
    }
};

string buildFinalText(string input) {
    Stack st(input.length());

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '#') {
            st.pop();         
        } else {
            st.push(input[i]); 
        }
    }

    return st.getResult();
}

bool areEqual(string s, string t) {
    string finalS = buildFinalText(s);
    string finalT = buildFinalText(t);
    return finalS == finalT;
}

int main() {
    string s, t;
    cout << "Enter string s: ";
    getline(cin, s);
    cout << "Enter string t: ";
    getline(cin, t);

    if (areEqual(s, t))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}