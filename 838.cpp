#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string pushDominoes(string& dominoes) {
        int prevRight = -1;
        int prevLeft = 0;
        for (int i = 0; i < dominoes.size(); i++) {
            if (dominoes[i] == 'L') {
                int j = i;
                while (j > (prevRight == -1 ? prevLeft : i - ((i - prevRight) / 2))) {
                    dominoes[j] = 'L';
                    j--;
                }
                if (prevRight != -1 && (i - prevRight) % 2 == 0) {
                    dominoes[j] = '.';
                }
                else {
                    dominoes[j] = 'L';
                }
                prevRight = -1;
                prevLeft = i;
            }
            else if (dominoes[i] == 'R') {
                prevRight = i;
            }
            else {
                if (prevRight != -1) {
                    dominoes[i] = 'R';
                }
            }
        }
        return dominoes;
    }
};

int main() {
    Solution s;
    string dominoes = "L";
    cout << s.pushDominoes(dominoes) << endl;
    return 0;
}