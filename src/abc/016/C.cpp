#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
int n, m;
vector<vector<int>> p;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  p.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    set<int> s;
    for (auto &j : p[i]) s.insert(j);
    set<int> ans;
    for (auto &j : s) {
      for (auto &k : p[j]) {
        if (s.find(k) != s.end()) continue;
        if (k == i) continue;
        ans.insert(k);
      }
    }
    cout << ans.size() << endl;
  }

  return 0;
}
