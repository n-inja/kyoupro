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
  cin >> n;
  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    mp[s]++;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    mp[s]--;
  }
  int ans = 0;
  for (auto &v : mp) {
    ans = max(ans, v.second);
  }
  cout << ans << endl;
  return 0;
}
