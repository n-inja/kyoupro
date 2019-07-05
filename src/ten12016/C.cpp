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

ll dp[202020] = {0};

struct Lap {
  Trie *p;
};

int main() {
  int n;
  string s;
  cin >> s >> n;
  vector<pair<string, ll>> ps(n);
  for (int i = 0; i < n; i++) cin >> ps[i].first;
  for (int i = 0; i < n; i++) cin >> ps[i].second;

  Trie *root = new Trie();

  for (int i = 0; i < n; i++) root->update(ps[i].first, 0, ps[i].second);

  dp[0] = 0;

  queue<Lap> q;
  q.push(Lap{root});

  for (int i = 0; i < s.size(); i++) {
    int size = q.size();
    dp[i + 1] = dp[i];
    for (int j = 0; j < size; j++) {
      auto p = q.front().p->next(s[i]);
      q.pop();
      if (p != nullptr) {
        dp[i + 1] = max(dp[i + 1], dp[i + 1 - p->d] + p->score);
        q.push(Lap{p});
      }
    }
    q.push(Lap{root});
  }

  cout << dp[s.size()] << endl;
  delete root;

  return 0;
}