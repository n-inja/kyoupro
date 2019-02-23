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
  int n;
  cin >> n;
  ll a = -1, b = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    ll c, d;
    cin >> c >> d;
    if (a == c && b == d)
      continue;
    ans += max(0LL, min(c, d) - (max(a, b) + (a == b ? 1 : 0)) + 1);
    a = c;
    b = d;
  }
  cout << ans << endl;
  return 0;
}
