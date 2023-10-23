#include <bits/stdc++.h>

using namespace std;


class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger>& getList() const;
};


class NestedIterator {
private:
    vector<int> flat;
    int i = 0;

    void flatten(const vector<NestedInteger>& nestedList) {
        for (auto& x : nestedList) {
            if (x.isInteger()) {
                flat.push_back(x.getInteger());
            }
            else {
                flatten(x.getList());
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        flatten(nestedList);
    }
    
    int next() {
        return flat[i++];
    }
    
    bool hasNext() {
        return i < flat.size();
    }
};
