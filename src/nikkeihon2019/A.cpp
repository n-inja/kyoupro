#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

ll dp[4040][4040] = {0};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vll a(n), s(n + 1);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    s[i + 1] = s[i] + a[i];
  for (int i = 1; i <= n; i++) {
    ll ans = 0;
    for (int j = 0; j <= n - i; j++) {
      ans = max(ans, s[j + i] - s[j]);
    }
    cout << ans << endl;
  }
  return 0;
}
