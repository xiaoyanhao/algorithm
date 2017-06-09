#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int count = 0;
 
struct TrieNode {
    int next[26];
    int trie;
    bool end_of_word;
}root[1000000];

void insertTrie(const char *s) {
    int i, j = 0, len = strlen(s);
    for (i = 0; i < len; i++) {
        int index = s[i] - 'a';
        if (!root[j].next[index]) {
            root[j].next[index] = ++count;
        }
        j = root[j].next[index];
    }
    root[j].end_of_word = true;
}

void buildTrie() {
    queue<int> q;
    int i, p;
    q.push(0);
    while (!q.empty()) {
        p = q.front();
        q.pop();
        if (root[root[p].trie].end_of_word) {
            root[p].end_of_word = true; 
        }
        for (i = 0; i < 26; i++) {
            if (root[p].next[i]) {
                q.push(root[p].next[i]);
                if (p) {
                    root[root[p].next[i]].trie = root[root[p].trie].next[i];
                }
            } else {
                root[p].next[i] = root[root[p].trie].next[i];
            }
        }
    }
}

bool queryTrie(const char *s) {
    int i, p = 0, len = strlen(s);
    for (i = 0; i < len; i++) {
        p = root[p].next[s[i] - 'a'];
        if (root[p].end_of_word) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    char word[100010], essay[1000010];
    cin >> n;
    while (n--) {
        cin >> word;
        insertTrie(word);
    }
    buildTrie();
    cin >> essay;
    if (queryTrie(essay)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

