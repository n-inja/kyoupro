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
  int m, n;
  cin >> m >> n;
  vector<int> cnt(n);
  vector<set<int>> v(m);
  for (int i = 0; i < m; i++) {
    int s;
    cin >> s;
    int a;
    for (int j = 0; j < s; j++) {
      cin >> a;
      v[i].insert(a);
    }
  }
  bool ok = true;
  for (int i = 0; i < m; i++) {
    bool ng = false;
    for (int j = i + 1; j < m; j++) {
      int c = 0;
      for (auto &a : v[i])
        if (v[j].find(a) != v[j].end()) c++;
      if (c == 0) ng = true;
    }
    if (ng) ok = false;
  }
  if (ok) cout << "possible" << endl;
  else cout << "impossible" << endl;
  return 0;
}
