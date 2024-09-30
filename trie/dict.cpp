#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    bool end;
    Node *next[26];
    Node() {
        end = false;
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
};

class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }

    ~Trie() {
        deleteTrie(root);
    }

    void insert(string &s) {
        Node *it = root;
        for (char c : s) {
            if (!it->next[c - 'a']) {
                it->next[c - 'a'] = new Node();
            }
            it = it->next[c - 'a'];
        }
        it->end = true;
    }

    void search(string &s) {
        Node *it = root;
        bool found = true;
        for (char c : s) {
            if (!it->next[c - 'a']) {
                found = false;
                break;
            }
            it = it->next[c - 'a'];
        }
        if (!found) {
            cout << "Prefix not found. Inserting the string: " << s << endl;
            insert(s);
            return;
        }
        
        vector<string> res;
        printAll(it, s, res, s); // Append the prefix 's' to the result

        if (res.empty()) {
            cout << "No words found with this prefix: " << s << endl;
        } else {
            for (auto u : res) {
                cout << u << endl;
            }
        }
    }

    void printAll(Node *it, string &prefix, vector<string> &res, string currentWord) {
        if (it == NULL) return;

        if (it->end) {
            res.push_back(currentWord);  // Add the whole word to the result
        }

        for (int i = 0; i < 26; i++) {
            if (it->next[i]) {
                printAll(it->next[i], prefix, res, currentWord + char('a' + i));
            }
        }
    }

private:
    void deleteTrie(Node *it) {
        if (it == NULL) return;
        for (int i = 0; i < 26; i++) {
            if (it->next[i]) {
                deleteTrie(it->next[i]);
            }
        }
        delete it;
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;
    vector<string> s(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        t.insert(s[i]);
    }

    int q;
    cin >> q;

    while (q--) {
        string rs;
        cin >> rs;
        t.search(rs);
    }

    return 0;
}
