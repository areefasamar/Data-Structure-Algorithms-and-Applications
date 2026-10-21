// Areefa Samar - CT-25062
// Question 04 (Lab 05)

#include <iostream>
#include <vector>
using namespace std;

class ProductOfNumbers {
private:
    vector<int> prefix; 

public:
    ProductOfNumbers() {
        prefix.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            prefix.clear();       
            prefix.push_back(1);
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k) {
        int n = prefix.size();
        if (k >= n) {
            return 0;             
        }
        return prefix[n - 1] / prefix[n - 1 - k];
    }
};

int main() {
    ProductOfNumbers p;
    p.add(3);
    p.add(0);
    p.add(2);
    p.add(5);
    p.add(4);
    cout << p.getProduct(2) << endl;   
    cout << p.getProduct(3) << endl;  
    cout << p.getProduct(4) << endl; 
    p.add(8);
    cout << p.getProduct(2) << endl;   
    return 0;
}