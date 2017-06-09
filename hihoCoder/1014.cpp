#include <iostream>

using namespace std;

struct Trie {
    int count;
    Trie *next[26];
    Trie() {
        count = 0;
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
};

void insertTrie(string word, Trie *(&root)) {
    Trie *node = root;
    int len = word.size();
    for (int i = 0; i < len; i++) {
        int index = word[i] - 'a';
        if (node->next[index] == NULL) {
            Trie *tmp = new Trie;
            tmp->count++;
            node->next[index] = tmp;
            node = tmp;
        } else {
            node = node->next[index];
            node->count++;
        }
    }
}

int queryTrie(string word, Trie *(&root)) {
    Trie *node = root;
    int len = word.size();
    for (int i = 0; i < len; i++) {
        int index = word[i] - 'a';
        if (node->next[index] == NULL) {
            return 0;
        }
        node = node->next[index];
    }
    return node->count;
}

int main() {
    int n, m;
    string word, query;
    Trie *root = new Trie;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> word;
        insertTrie(word, root);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> query;
        cout << queryTrie(query, root) << endl;
    }

    return 0;
}

