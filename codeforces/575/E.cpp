#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

void solve() {
  int b, w;
  bool m = false;
  cin >> b >> w;
  if (b > w) {
    m = true;
    swap(b, w);
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i < b; i++) {
    ans.emplace_back(3 + i * 2, 2);
    ans.emplace_back(3 + i * 2 + 1, 2);
  }
  vector<pair<int, int>> rest;
  rest.emplace_back(2, 2);
  for (int i = 0; i < b; i++) {
    rest.emplace_back(3 + i * 2, 1);
    rest.emplace_back(3 + i * 2, 3);
  }
  if (w - b < 0 || w - b > rest.size()) {
    cout << "NO" << endl;
    return;
  }
  for (int i = 0; i < w - b; i++) ans.push_back(rest[i]);
  cout << "YES" << endl;
  for (auto &v : ans) {
    cout << v.first + m << " " << v.second << endl;
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
