#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n - 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  int c = 0;
  vector<int> ids(n);
  set<int> look;
  for (int i = 0; i < n; i++) look.insert(i);
  for (int i = 0; i < n * n; i++) {
    set<int> update;
    for (auto it = look.begin(); it != look.end(); it++) {
      int j = *it;
      if (ids[j] >= n - 1) {
        continue;
      }
      int to = a[j][ids[j]];
      if (ids[to] >= n - 1) {
        continue;
      }
      if (a[to][ids[to]] == j) {
        update.insert(to);
        update.insert(j);
      }
    }
    if (update.empty()) {
      cout << -1 << endl;
      return 0;
    }
    look.clear();
    for (auto &j : update) {
      ids[j]++;
      look.insert(j);
      c++;
    }
    if (c == n * (n - 1)) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  return 0;
}
