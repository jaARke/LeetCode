#include <iostream>
#include <stack>

using namespace std;

int main() {
    string in;
    cin >> in;
    int i = 1;
    int j = 0;
    stack<int> s;
    int count = 0;
    while (i < in.length()) {
        if (in[i] == in[j]) {
            count++;
            while (!s.empty() && in[i + 1] == in[s.top()]) {
                count++;
                i++;
                s.pop();
            }
            i++;
            j = i;
            i++;
        }
        else {
            s.push(j); 
            j = i;
            i++;
        }
    }
    if (count % 2 == 0) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }
    return 0;
}