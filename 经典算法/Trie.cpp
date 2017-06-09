# include <iostream>
# include <cstring>
using namespace std;

struct TrieNode {
    int count;
    TrieNode *next[26];
    TrieNode() {
        count = 0;
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
}*root;

void insertTrie(const char *s) {
    TrieNode *p = root;
    int i, len = strlen(s);
    for (i = 0; i < len; i++) {
        int index = s[i] - 'a';
        if (p->next[index] == NULL) {
            TrieNode *temp = new TrieNode;
            temp->count++;
            p->next[index] = temp;
            p = temp; 
        } else {
            p = p->next[index];
            p->count++;
        }
    }
}

int queryTrie(const char* s) {
    TrieNode *p = root;
    int i, len = strlen(s);
    for (i = 0; i < len; i++) {
        int index = s[i] - 'a';
        if (p->next[index] == NULL) {
            return 0;
        }
        p = p->next[index];
    }
    return p->count;
}

void deleteTrie(TrieNode *p) {
    for (int i = 0; i < 26; i++) {
        if (p->next[i]) {
            deleteTrie(p->next[i]);
        }
    }
    delete p;
}

int main() {
    int n, m, i;
    char s[15];
    cin >> n;
    root = new TrieNode;
    for (i = 0; i < n; i++) {
        cin >> s;
        insertTrie(s);
    }
    cin >> m;
    for (i = 0; i < m; i++) {
        cin >> s;
        cout << queryTrie(s) << endl;
    }
    deleteTrie(root);
    return 0;
}

