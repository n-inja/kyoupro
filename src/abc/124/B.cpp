#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vll v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  ll now = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    now = max(now, v[i]);
    if (now <= v[i])
      ans++;
  }
  cout << ans << endl;
  return 0;
}
