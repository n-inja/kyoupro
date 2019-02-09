#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll k, a, b;
  cin >> k >> a >> b;
  ll ans = k + 1;
  ll ret = 0;
  if (b > a) {
    k -= a;
    if (k > 0) {
      k--;
      ret += b;
      ret += (b - a) * (k / 2);
      if (k % 2)
        ret++;
      ans = max(ans, ret);
    }
  }
  cout << ans << endl;
  return 0;
}
