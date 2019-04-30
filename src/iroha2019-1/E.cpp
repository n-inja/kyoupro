#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll calc(ll n, ll a) { return n - n / a; }

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n, a, b;
  cin >> n >> a >> b;
  vll d(b);
  for (int i = 0; i < b; i++)
    cin >> d[i];
  if (b == 0) {
    cout << n - (n / a) << endl;
    return 0;
  }
  d.push_back(0);
  d.push_back(n + 1);
  sort(d.begin(), d.end());

  ll ans = 0;
  for (int i = 1; i < d.size(); i++) {
    ans += calc(d[i] - d[i - 1] - 1, a);
  }

  cout << ans << endl;
  return 0;
}
