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
  int n, m;
  cin >> n >> m;
  vll x(m);
  for (int i = 0; i < m; i++)
    cin >> x[i];
  sort(x.begin(), x.end());
  if (m == 1) {
    cout << 0 << endl;
    return 0;
  }
  vll sub(m - 1);
  ll ans = 0;
  for (int i = 0; i < m - 1; i++)
    ans += sub[i] = x[i + 1] - x[i];
  sort(sub.begin(), sub.end());
  reverse(sub.begin(), sub.end());
  for (int i = 0; i < n - 1 && i < sub.size(); i++) {
    ans -= sub[i];
  }
  cout << ans << endl;
  return 0;
}
