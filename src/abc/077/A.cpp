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
  string s, t;
  cin >> s >> t;
  string si = s, ti = t;
  reverse(si.begin(), si.end());
  reverse(ti.begin(), ti.end());
  if (s == ti && t == si) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
