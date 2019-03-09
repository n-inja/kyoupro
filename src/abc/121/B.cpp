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
  ll n, m, c;
  cin >> n >> m >> c;
  vll b(m);
  for (int i = 0; i < m; i++)
    cin >> b[i];
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    vll a(m);
    for (int j = 0; j < m; j++)
      cin >> a[j];
    ll sum = c;
    for (int j = 0; j < m; j++)
      sum += a[j] * b[j];
    if (sum > 0)
      ans++;
  }
  cout << ans << endl;
  return 0;
}
