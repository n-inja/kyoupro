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
  ll n, m, k;
  cin >> n >> m >> k;
  vll a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  ll t = a[0] * k + a[1];
  ll ans = m / (k + 1) * t + (m % (k + 1)) * a[0];
  cout << ans << endl;
  return 0;
}
