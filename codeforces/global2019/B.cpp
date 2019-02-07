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
  vll v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  ll ans = v[n - 1] - v[0] + 1;
  vll rest;
  for (int i = 0; i < n - 1; i++)
    rest.push_back(v[i + 1] - v[i] - 1);
  sort(rest.begin(), rest.end());
  reverse(rest.begin(), rest.end());
  for (int i = 0; i < k - 1; i++) {
    ans -= rest[i];
  }
  cout << ans << endl;
  return 0;
}
