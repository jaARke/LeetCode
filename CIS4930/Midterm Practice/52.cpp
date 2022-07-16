#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<long long> table(30001, 0);
    vector<int> denoms = {1, 5, 10, 25, 50};
    table[0] = 1;
    for (int i =0; i < denoms.size(); i++) {
        for (int j = denoms[i]; j <= 30000; j++) {
            table[j] += table[j - denoms[i]];
        }
    }

    string in;
    while (getline(cin, in)) {
        if (table[stoi(in)] == 1) {
            cout << "There is only 1 way to produce " << in << " cents change." << endl;
        }
        else {
            cout << "There are " << table[stoi(in)] << " ways to produce " << in << " cents change." << endl;
        }
    }
    return 0;
}