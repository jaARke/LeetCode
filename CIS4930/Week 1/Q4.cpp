#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n != -1) {
        int prevHours = 0;
        int totMiles = 0;
        for (int i = 0; i < n; i++) {
            int mph;
            int hours;
            cin >> mph;
            cin >> hours;
            totMiles += mph * (hours - prevHours);
            prevHours = hours;
        }
        cout << totMiles << " miles" << endl;
        cin >> n;
    }
    return 0;
}