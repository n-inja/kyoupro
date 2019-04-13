#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

struct Trie {
  int value;
  Trie *next[0x100];
  Trie() {
    fill(next, next + 0x100, nullptr);
    value = 0;
  }
};
Trie *find(string t, Trie *r) {
  r->value++;
  for (int i = 0; i < t.size(); i++) {
    char c = t[i];
    if (!r->next[c])
      r->next[c] = new Trie;
    r = r->next[c];
    r->value++;
  }
  return r;
}
void del(Trie *r) {
  for (int i = 0; i < 0x100; i++) {
    if (r->next[i]) {
      del(r->next[i]);
    }
  }
  delete r;
}

int dfs(Trie *t) {
  if (t->value == 2) {
    return 2;
  }
  ll ret = 0;
  for (int i = 0; i < 0x100; i++) {
    if (t->next[i]) {
      ret += dfs(t->next[i]);
    }
  }
  if (t->value - ret >= 2)
    ret += 2;
  return ret;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int q = 0; q < t; q++) {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      reverse(v[i].begin(), v[i].end());
      v[i].push_back('$');
    }
    Trie *tree = new Trie;
    for (int i = 0; i < n; i++) {
      find(v[i], tree);
    }
    ll ans = 0;
    for (int i = 0; i < 0x100; i++) {
      if (tree->next[i]) {
        ans += dfs(tree->next[i]);
      }
    }
    cout << "Case #" << q + 1 << ": " << ans << endl;
    del(tree);
  }
  return 0;
}
