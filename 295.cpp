#include <bits/stdc++.h>

using namespace std;

class MedianFinder {
private:
    multiset<int> m;
    multiset<int>::iterator iter = m.begin();
    bool odd = false;

public:
    MedianFinder() {}
    
    void addNum(int num) {
        m.insert(num);
        odd = !odd;

        if (m.size() == 1 || (num >= *iter && !odd)) {
            iter++;
        }
        else if (num < *iter && odd) {
            iter--;
        }
    }
    
    double findMedian() {
        if (!odd) {
            return (*iter + *prev(iter)) / 2.0;
        }
        else {
            return *iter;
        }
    }
};

int main() {
    MedianFinder m;
    m.addNum(1);
    m.addNum(2);
    cout << m.findMedian() << endl;
    m.addNum(3);
    cout << m.findMedian() << endl;
    return 0;
}