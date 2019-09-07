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
  int n, k;
  string s;
  cin >> n >> k >> s;
  int diff = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) diff++;
  }
  ll ans = n - 1;
  if (k * 2 > diff) {
    cout << ans << endl;
  } else {
    cout << ans - (diff - 2 * k) << endl;
  }
  return 0;
}
