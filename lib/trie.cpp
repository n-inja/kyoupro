#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int TRIE_SIZE = 26;
const int TRIE_OFFSET = 'a';

struct Trie {
  int d, size;
  Trie *child[TRIE_SIZE];

  ll score = 0;

  Trie() {
    d = 0;
    size = 0;
    for (int i = 0; i < TRIE_SIZE; i++) child[i] = nullptr;
  }

  void update(string &s, int i, ll v) {
    size++;
    d = i;
    if (i < s.size()) {
      if (child[s[i] - TRIE_OFFSET] == nullptr)
        child[s[i] - TRIE_OFFSET] = new Trie();

      child[s[i] - TRIE_OFFSET]->update(s, i + 1, v);
    } else {
      score = v;
    }
  }

  Trie *next(char c) {
    return child[c - TRIE_OFFSET];
  }

  ~Trie() {
    for (int i = 0; i < TRIE_SIZE; i++) {
      if (child[i] != nullptr) delete child[i];
    }
  }
};