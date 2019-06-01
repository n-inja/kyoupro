#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll solve(ll a, ll b, ll c) {
  ll ans = 0;
  if (c > 0) {
    if (b) {
      ans += 1;
      b--;
    }
  }
  ans += c * 2;
  ans += min(a, b) * 2;
  a -= min(a, b);
  b -= min(a, b);
  if (a) ans++;
  return ans;
}

ll solve2(ll a, ll b, ll c) {
  ll ans = 0;
  ans += c * 2;
  ans += min(a, b) * 2;
  a -= min(a, b);
  b -= min(a, b);
  if (a) ans++;
  return ans;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll a, b, c;
  cin >> a >> b >> c;

  cout << max(solve(a, b, c), solve2(a, b, c)) << endl;
  return 0;
}
