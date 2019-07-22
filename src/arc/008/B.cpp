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
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  map<char, int> scnt, tcnt;
  for (auto &c : s) scnt[c]++;
  for (auto &c : t) tcnt[c]++;
  int ans = 0;
  for (auto &v : scnt) {
    if (tcnt[v.first] == 0) {
      cout << -1 << endl;
      return 0;
    }
    ans = max(ans, (v.second + tcnt[v.first] - 1) / tcnt[v.first]);
  }
  cout << ans << endl;

  return 0;
}
