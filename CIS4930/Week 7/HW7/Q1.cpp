#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int check(int n, vector<int>& seq) {
    int rest = 0, prev = 0;    // prev = 0 - rested, prev = 1 - wrote, prev = 2 - played
    for (int i = 0; i < n; i++) {
        switch (seq[i]) {
            case 0:
                rest++;
                prev = 0;
                break;
            case 1:
                if (prev != 1) {
                    prev = 1;
                }
                else {
                    rest++;
                    prev = 0;
                }
                break;
            case 2:
                if (prev != 2) {
                    prev = 2;
                }
                else {
                    rest++;
                    prev = 0;
                }
                break;
            default:
                if (prev == 0) {
                    while (seq[i] == 3) {
                        if (i == n - 1) {
                            return rest;
                        }
                        i++;
                    }
                    if (seq[i] == 0 || seq[i] == 2) {
                        prev = 1;
                    }
                    else {
                        prev = 2;
                    }
                    i--;    // Ensures correct loop behavior
                }
                else if (prev == 1) {
                    prev = 2;
                }
                else {
                    prev = 1;
                }
                break;     
        } 
    }
    return rest;
}


int main() {
    int n;
    cin >> n;

    vector<int> seq;
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        seq.push_back(ai);
    }
    cout << check(n, seq) << endl;
    return 0;
}