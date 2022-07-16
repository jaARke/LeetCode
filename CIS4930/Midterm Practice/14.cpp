#include <iostream>

using namespace std;

int main() {
    string in;
    while(getline(cin, in)) {
        int n = stoi(in);
        if (n == -1) {
            break;
        }
        int prev = 0, result = 0;
        for (int i = 0; i < n; i++) {
            int mph, time;
            cin >> mph >> time;
            result += mph * (time - prev);
            prev = time;
        }
        cout << result << " miles" << endl;
        cin.ignore();
    }
    return 0;
}