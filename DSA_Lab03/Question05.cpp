// Areefa Samar - CT-25062
// Question 05 (Lab 03)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BrowserHistory {
private:
    vector<string> history;
    int current;

public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        current = 0;
    }

    void visit(string url) {
        history.erase(history.begin() + current + 1, history.end());
        history.push_back(url);
        current++;
    }

    string back(int steps) {
        current = current - steps;
        if (current < 0) current = 0;
        return history[current];
    }

    string forward(int steps) {
        current = current + steps;
        if (current > (int)history.size() - 1) current = history.size() - 1;
        return history[current];
    }
};

int main() {
    BrowserHistory browserHistory("leetcode.com");

    browserHistory.visit("google.com");    
    browserHistory.visit("facebook.com");   
    browserHistory.visit("youtube.com");    

    cout << browserHistory.back(1) << endl;     
    cout << browserHistory.back(1) << endl;     
    cout << browserHistory.forward(1) << endl;  

    browserHistory.visit("linkedin.com");       

    cout << browserHistory.forward(2) << endl;  
    cout << browserHistory.back(2) << endl;     
    cout << browserHistory.back(7) << endl;     

    return 0;
}