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
  string s;
  cin >> s;
  int n = s.size();
  ll ans = 0;
  ll wsum = 0, osum = 0;
  for (int i = 1; i < n; i++) {
    if (s[i - 1] == 'v' && s[i] == 'v') {
      wsum++;
      ans += osum;
    }
    if (s[i] == 'o') {
      osum += wsum;
    }
  }
  cout << ans << endl;
  return 0;
}
