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
  if (s.back() == t[0] && t.back() == u[0]) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
