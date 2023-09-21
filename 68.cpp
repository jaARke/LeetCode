#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int currLineChars = 0;
        int currLineStart = 0;
        for (int i = 0; i < words.size(); i++) {
            int wordsOnLine = i - currLineStart;
            if (words[i].length() + (currLineChars + wordsOnLine) > maxWidth) {
                // The current word cannot be included on the current line -> format the current line without it
                int padding = maxWidth - (currLineChars + wordsOnLine - 1); // Leftover padding
                if (wordsOnLine == 1) {
                    words[i - 1] += string(padding, ' ');
                    res.push_back(words[i - 1]);
                    currLineStart = i;
                    currLineChars = words[i].length();
                    continue;
                }
                int paddingSplit = padding / (wordsOnLine - 1); // How much padding each space gets
                int leftover = padding % (wordsOnLine - 1); // The leftover padding for the leftmost spaces

                string line = "";
                for (int j = currLineStart; j < i - 1; j++) {
                    words[j] += string(paddingSplit + 1, ' ');
                    if (leftover > 0) {
                        leftover--;
                        words[j] += ' ';
                    }
                    line += words[j];
                }
                line += words[i - 1];

                res.push_back(line);
                currLineChars = 0;
                currLineStart = i;
            }
            currLineChars += words[i].length();
        }

        string line = "";
        for (int i = currLineStart; i < words.size() - 1; i++) {
            line += words[i] + " ";
        }
        words.back() += string(maxWidth - (currLineChars + (words.size() - currLineStart - 1)), ' ');
        line += words.back();
        res.push_back(line);

        return res;
    }
};

int main() {
    Solution s;
    vector<string> words = {"What","must","be","acknowledgment","shall","be"};
    int maxWidth = 16;
    auto res = s.fullJustify(words, maxWidth);
    cout << "Done!" << endl;
    return 0;
}