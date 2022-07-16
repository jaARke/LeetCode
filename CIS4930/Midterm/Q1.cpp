#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    map<string, int> mons;
    for (int i = 0; i < n; i++) {
        string mi;
        getline(cin, mi);
        mons[mi]++;
    }
    auto iter = mons.begin();
    while (iter != mons.end()) {
        cout << "Release " << iter->second - 1 << " of your " << iter->first << "s." << endl;
        iter++;
    }
    return 0;
}