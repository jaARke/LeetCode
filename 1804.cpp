#include <bits/stdc++.h>

using namespace std;

class Trie {
private:
    struct Node {
        int charCount = 0, wordCount = 0;
        vector<Node*> v = vector<Node*>(26, nullptr);

        ~Node() {
            for (auto i : v) {
                delete i;
            }
        }
    };
    Node* head = new Node();

public:
    Trie() {}
    ~Trie() { delete head; }
    
    void insert(string word) {
        Node* n = head;
        for (int i = 0; i < word.length(); i++) {
            if (!(n->v[word[i] - 'a'])) {
                n->v[word[i] - 'a'] = new Node();
            }
            n = n->v[word[i] - 'a'];
            n->charCount++;
        }
        n->wordCount++;
    }
    
    int countWordsEqualTo(string word) {
        Node* n = head;
        for (int i = 0; i < word.length(); i++) {
            if (!(n->v[word[i] - 'a'])) {
                return 0;
            }
            n = n->v[word[i] - 'a'];
        }
        return n->wordCount;
    }
    
    int countWordsStartingWith(string prefix) {
        Node* n = head;
        for (int i = 0; i < prefix.length(); i++) {
            if (!(n->v[prefix[i] - 'a'])) {
                return 0;
            }
            n = n->v[prefix[i] - 'a'];
        }
        return n->charCount;
    }
    
    void erase(string word) {
        Node* n = head;
        for (int i = 0; i < word.length(); i++) {
            if (!(n->v[word[i] - 'a'])) {
                return;
            }
            n = n->v[word[i] - 'a'];
            n->charCount--;
        }
        n->wordCount--;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */