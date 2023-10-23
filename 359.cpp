#include <bits/stdc++.h>

using namespace std;

int speed_up = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    return 0;
}();

class Logger {
private:
    unordered_map<string, int> messages;

public:
    Logger() {}
    
    bool shouldPrintMessage(int timestamp, string message) {
        auto iter = messages.find(message);
        if (iter == end(messages) || iter->second <= timestamp) {
            messages[message] = 10 + timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */