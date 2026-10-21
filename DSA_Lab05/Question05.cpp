// Areefa Samar - CT-25062
// Question 05 (Lab 05)

#include <iostream>
using namespace std;

class DataStream {
private:
    int value;
    int k;
    int count;  

public:
    DataStream(int v, int kk) {
        value = v;
        k = kk;
        count = 0;
    }

    bool consec(int num) {
        if (num == value) {
            count++;
        } else {
            count = 0;
        }
        return count >= k;
    }
};

int main() {
    DataStream ds(4, 3);
    cout << boolalpha;
    cout << ds.consec(4) << endl;   
    cout << ds.consec(4) << endl;   
    cout << ds.consec(4) << endl;   
    cout << ds.consec(3) << endl;   
    return 0;
}