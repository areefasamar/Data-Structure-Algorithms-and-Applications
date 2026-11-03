// Areefa Samar - CT-25062
// Question 05 (Lab 07)

#include <iostream>
#include <vector>
using namespace std;

bool carPooling(vector<vector<int> >& trips, int capacity) {
    int maxLocation = 0;
    for (int i = 0; i < (int)trips.size(); i++) {
        if (trips[i][2] > maxLocation)
            maxLocation = trips[i][2];
    }

    vector<int> change(maxLocation + 1, 0);
    for (int i = 0; i < (int)trips.size(); i++) {
        change[trips[i][1]] += trips[i][0];
        change[trips[i][2]] -= trips[i][0];
    }

    int passengers = 0;
    for (int i = 0; i <= maxLocation; i++) {
        passengers += change[i];
        if (passengers > capacity)
            return false;
    }
    return true;
}

vector<int> makeTrip(int p, int from, int to) {
    vector<int> t;
    t.push_back(p);
    t.push_back(from);
    t.push_back(to);
    return t;
}

int main() {
    vector<vector<int> > trips;
    trips.push_back(makeTrip(2, 1, 5));
    trips.push_back(makeTrip(3, 3, 7));

    cout << "Example 1 Output: " << (carPooling(trips, 4) ? "true" : "false") << endl;
    cout << "Example 2 Output: " << (carPooling(trips, 5) ? "true" : "false") << endl;

    return 0;
}
