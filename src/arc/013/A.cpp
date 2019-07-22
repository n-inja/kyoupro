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
  ll n, m, l;
  ll p[3];
  cin >> n >> m >> l >> p[0] >> p[1] >> p[2];
  ll ans = 0;
  sort(p, p + 3);
  do {
    ans = max(ans, (l / p[0]) * (n / p[1]) * (m / p[2]));
  } while (next_permutation(p, p + 3));

  cout << ans << endl;
  return 0;
}
