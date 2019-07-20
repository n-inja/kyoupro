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
  vector<string> s(n);
  map<string, int> mp;
  for (int i = 0; i < n; i++) cin >> s[i], mp[s[i]]++;
  int c = 0;
  string ans;
  for (auto &v : mp) if (c < v.second) ans = v.first, c = v.second;
  cout << ans << endl;
  return 0;
}
