#include <unordered_map>
#include <stack>
#include <iostream>

using namespace std;

/*
 * To do this problem, we keep a freqMap with stack elements as keys and frequencies as values. We also keep a stackMap
 * with frequencies as keys and stacks as values. The stacks hold the elements for each frequency.
 * When an element is pushed, we increase its frequency in freqMap and push it onto the corresponding frequency stack in
 * stackMap.
 * When an element is popped, we use the maxFreq attribute to access the correct stackMap stack and pop the top element. We
 * also decrease that element's frequency in freqMap.
 */

class FreqStack {
private:
    unordered_map<int, int> freqMap;
    unordered_map<int, stack<int>> stackMap;
    int maxFreq;

public:
    FreqStack() {
        maxFreq = 0;
    }

    void push(int val) {
        maxFreq = max(maxFreq, ++freqMap[val]);
        stackMap[freqMap[val]].push(val);
    }

    int pop() {
        int result = stackMap[maxFreq].top();
        stackMap[maxFreq].pop();
        /*
         * If the maxFreq stack is empty, decrease the variable value. This value is guaranteed to exist in the map because
         * frequencies build on each other. If there is an element with frequency of 3, that element was first at frequency of 2
         * and so a stack exists in stackMap at frequency 2 with the element in it.
         */

        if (stackMap[maxFreq].empty()) {
            maxFreq--;
        }
        freqMap[result]--;
        return result;
    }
};

int main() {
    auto* obj = new FreqStack();
    obj->push(5);
    obj->push(7);
    obj->push(5);
    obj->push(7);
    obj->push(4);
    obj->push(5);
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    delete obj;
    return 0;
}