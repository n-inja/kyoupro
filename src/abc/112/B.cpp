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
  int n, t;
  cin >> n >> t;
  int ans = 11111111;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (b <= t)
      ans = min(ans, a);
  }
  if (ans > 100000)
    cout << "TLE" << endl;
  else
    cout << ans << endl;
  return 0;
}
