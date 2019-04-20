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
  string s;
  cin >> s;
  vll lw(n + 1), rb(n + 1);
  for (int i = 0; i < n; i++) {
    lw[i + 1] = lw[i];
    if (s[i] == '#')
      lw[i + 1]++;
  }
  for (int i = n; i > 0; i--) {
    rb[i - 1] = rb[i];
    if (s[i - 1] == '.') {
      rb[i - 1]++;
    }
  }
  ll ans = n;
  for (int i = 0; i <= n; i++) {
    ans = min(ans, lw[i] + rb[i]);
  }
  cout << ans << endl;
  return 0;
}
