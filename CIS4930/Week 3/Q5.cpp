#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h> 

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> xCoords;
    vector<int> yCoords;
    long long count = 0;
    for(int i = 0; i < n; i++) {
        int x;
        int y;
        cin >> x;
        cin >> y;
        xCoords.push_back(x);
        yCoords.push_back(y);
    }

    sort(xCoords.begin(), xCoords.end());
    for(int i = 0; i < xCoords.size(); i++) {
        xCoords[i] -= i;
    }

    sort(xCoords.begin(), xCoords.end());
    sort(yCoords.begin(), yCoords.end());
    
    int xMedian = xCoords[xCoords.size() / 2];
    int yMedian = yCoords[yCoords.size() / 2];

    for(int i = 0; i < xCoords.size(); i++) {   // xCoords and yCoords are same size
        count += abs(xMedian - xCoords[i]);
        count += abs(yMedian - yCoords[i]);
    }
    cout << count << "\n";
    
    return 0;
}