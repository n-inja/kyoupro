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
  string s, t, u;
  cin >> s >> t >> u;
  string ans;
  ans.push_back(s[0] - 'a' + 'A');
  ans.push_back(t[0] - 'a' + 'A');
  ans.push_back(u[0] - 'a' + 'A');
  cout << ans << endl;
  return 0;
}
