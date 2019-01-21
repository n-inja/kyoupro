#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

struct I {
  int n;
  vll ng;
  I(vll &v) {
    n = v.size();
    ng = v;
  }
  int solve() {
    if (n <= 20) {
      int size = 1 << n;
      int ret = 0;
      for (int i = 0; i < size; i++) {
        int out = 0;
        int size = 0;
        for (int j = 0; j < n; j++) {
          out |= ((i >> j) & 1) ? ng[j] : 0;
          size += ((i >> j) & 1);
        }
        ret = max(ret, (i & out) ? 0 : size);
      }
      return ret;
    } else {
      int m = n - 20;
      int size = 1 << m;
      vi dp(size);
      dp[0] = 0;
      for (int i = 0; i < m; i++)
        dp[1 << i] = 1;
      for (int i = 1; i < size; i++) {
        if (!((i - 1) & i))
          continue;
        int out = 0;
        int size = 0;
        dp[i] = 0;
        for (int j = 0; j < m; j++) {
          dp[i] = max(dp[i], ((i >> j) & 1) ? dp[i ^ (1 << j)] : 0);
        }
        for (int j = 0; j < m; j++) {
          out |= ((i >> j) & 1) ? ng[j] : 0;
          size += ((i >> j) & 1);
        }
        dp[i] = (i & out) ? dp[i] : size;
      }
      size = 1 << 20;
      int ret = 0;
      int mask = (1 << m) - 1;
      for (int i = 0; i < size; i++) {
        ll out = 0;
        int size = 0;
        for (int j = m; j < n; j++) {
          out |= ((i >> (j - m)) & 1) ? ng[j] : 0;
          size += ((i >> (j - m)) & 1);
        }
        ret = max(ret, ((out >> m) & i) ? 0 : size + dp[(mask & out) ^ mask]);
      }
      return ret;
    }
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vll ng(m);
  map<string, int> mp;
  set<int> s;
  int id = 0;
  for (int i = 0; i < n; i++) {
    int j;
    cin >> j;
    if (j == 1) {
      for (auto &si : s) {
        for (auto &sj : s) {
          if (si == sj)
            continue;
          ng[si] |= 1LL << sj;
        }
      }
      s.clear();
    } else {
      string t;
      cin >> t;
      if (mp.find(t) == mp.end()) {
        mp[t] = id++;
      }
      s.insert(mp[t]);
    }
  }
  for (auto &si : s) {
    for (auto &sj : s) {
      if (si == sj)
        continue;
      ng[si] |= 1LL << sj;
    }
  }

  I solver(ng);
  cout << solver.solve() << endl;
  return 0;
}
