#include <iostream>
#include <math.h>
#include <map>

using namespace std;

int main() {
    string in;
    while (getline(cin, in)) {
        int n;
        int l;
        int w;
        n = stoi(in.substr(0, in.find(" ")));
        in.erase(0, in.find(" ") + 1);
        l = stoi(in.substr(0, in.find(" ")));
        in.erase(0, in.find(" ") + 1);
        w = stoi(in.substr(0, in.find(" ")));
        in.erase(0, in.find(" ") + 1);

        multimap<double, double> ranges;
        for (int i = 0; i < n; i++) {
            int x;
            int r;
            double r1;
            double r2;
            cin >> x;
            cin >> r;

            if (r * 2 < w) {
                continue;
            }
            double temp = sqrt(pow((double)r, 2) - pow(((double)w / 2), 2));
            r1 = x - temp;  // Left intersection point
            r2 = x + temp;  // Right intersection point
            ranges.emplace(r1, r2);
        }

        double globalMax = 0.0;
        int count = 0;
        while (globalMax < l) {
            auto iter = ranges.upper_bound(globalMax);
            if (iter == ranges.begin()) {  
                count = -1;
                break;
            }
            iter--;
            double localMax = iter->second;
            auto maxIter = iter;
            while (iter != ranges.begin()) {
                if (iter->second > localMax) {
                    localMax = iter->second;
                    maxIter = iter;
                }
                iter--;
            }
            if (iter->second > localMax) {
                localMax = iter->second;
                maxIter = iter;
            }
            globalMax = localMax;
            count++;
            ranges.erase(maxIter);
        }
        cout << count << endl;
        cin.ignore();
    }
    return 0;
}