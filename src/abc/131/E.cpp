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
  ll n, k;
  cin >> n >> k;
  vector<pair<int, int>> ps;
  for (int i = 1; i < n; i++) ps.emplace_back(0, i);
  ll now = (n - 1) * (n - 2) / 2;
  vector<pair<int, int>> qs;
  for (int i = 1; i < n; i++) for (int j = i + 1; j < n; j++) qs.emplace_back(i, j);
  if (now - k < 0) {
    cout << -1 << endl;
    return 0;
  }
  if (now - k > qs.size()) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < now - k; i++) {
    ps.push_back(qs[i]);
  }
  cout << ps.size() << endl;
  for (auto &v : ps) cout << v.first + 1 << " " << v.second + 1 << endl;

  return 0;
}
