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
  ll n;
  cin >> n;
  vll c(n);
  for (int i = 0; i < n; i++)
    cin >> c[i];
  if (c[0] != c[n - 1]) {
    cout << n - 1 << endl;
  } else {
    ll l, r;
    for (int i = 0; i < n; i++)
      if (c[i] != c[0]) {
        l = i;
        break;
      }
    for (int i = n - 1; i >= 0; i--)
      if (c[i] != c[0]) {
        r = i;
        break;
      }
    cout << max(n - 1 - l, r) << endl;
  }
  return 0;
}
