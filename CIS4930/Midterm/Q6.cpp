#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
 
 
int main() {
    int n;
    cin >> n;
    for (int tc = 0; tc < n; ++tc)
    {
        int k, e, r;
        cin >> k >> e >> r;
        priority_queue<int> ethan;
        priority_queue<int> red;
        int temp;
        for (int i = 0; i < e; ++i)
        {
            cin >> temp;
            ethan.push(temp);
        }
        for (int i = 0; i < r; ++i)
        {
            cin >> temp;
            red.push(temp);
        }
        while (!ethan.empty() && !red.empty())
        {
            //cout << "esize: " << ethan.size() << "rsize: " << red.size() << endl;
 
            vector<int> eteam, rteam;
            int deg = min(k, min((int) ethan.size(), (int) red.size()));
            for (int i = 0; i < deg; ++i)
            {
                int ei = ethan.top();
                int ri = red.top();
                ethan.pop();
                red.pop();
                if (ei > ri)
                    eteam.push_back(ei - ri);
                else if (ri > ei)
                    rteam.push_back(ri - ei);
            }
 
            /*cout << ethan.size();
            for (int i = 0; i < eteam.size(); ++i)
                cout << "eteam[" << i << "]: " << eteam[i] << "\n";
            for (int i = 0; i < rteam.size(); ++i)
                cout << "red[" << i << "]: " << rteam[i] << "\n";*/
 
            for (int i = 0; i < eteam.size(); ++i)
                ethan.push(eteam[i]);
            for (int i = 0; i < rteam.size(); ++i)
                red.push(rteam[i]);
        }
        if (ethan.empty() && !red.empty())
        {
            cout << "Red wins" << "\n";
            int s = red.size();
            for (int i = 0; i < s; ++i)
            {
                cout << red.top() << "\n";
                red.pop();
            }
        }
        else if (!ethan.empty() && red.empty())
        {
            cout << "Ethan wins" << "\n";
            int s = ethan.size();
            for (int i = 0; i < s; ++i)
            {
                cout << ethan.top() << "\n";
                ethan.pop();
            }
        }
        else
            cout << "Draw" << "\n";
        cout << "\n";
    }
    return 0;
}