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
  ll ans = 0;
  ans += n / 10 * 100;
  ans += min((n % 10) * 15, 100);
  cout << ans << endl;
  return 0;
}
