#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int targ;
    cin >> n;
    cin >> targ;

    long result = 0;
    long current = 0;
    vector<int> prices(n, 0);
    int j = 0;
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        prices.push_back(price);
        current += price;
        while (current > targ) {
            current -= prices[j];
            j++;
        }
        if (current > result) {
            result = current;
        }
        if (result == targ) { 
            break;
        }
    }
    cout << result;
    return 0;
}