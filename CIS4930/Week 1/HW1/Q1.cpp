#include <iostream>
#include <string>

using namespace std;

int main() {
    string raw;
    string result;
    cin >> raw;
    for (int i = 0; i < raw.length(); i++) {
        if (raw[i] == '<') {
            if (result.length() != 0) {
                result.pop_back();
            }
        }
        else {
            result.push_back(raw[i]);
        }
    }
    cout << result;
}