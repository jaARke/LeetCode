#include <string>
#include <algorithm>

using namespace std;

/*
 * You either know it or you don't type question. The number of deci-binary numbers will be the highest value digit
 * in the input number n. Simply find that digit and return it.
 */

class Solution {
public:
    int minPartitions(string n) {
        return *max_element(n.begin(), n.end()) - '0';
    }
};