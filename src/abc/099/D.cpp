#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, c;
  cin >> n >> c;
  vector<vector<ll>> d(c, vector<ll>(c));
  vector<vector<ll>> mp(n, vector<ll>(n));
  for (int i = 0; i < c; i++) for (int j = 0; j < c; j++) cin >> d[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> mp[i][j];
      mp[i][j]--;
    }
  vector<vector<ll>> cost(3, vector<ll>(c));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < c; k++) {
        cost[(i + j) % 3][k] += d[mp[i][j]][k];
      }
  ll INF = 1000000000000000LL;
  ll ans = INF;
  for (int i = 0; i < c; i++)
    for (int j = 0; j < c; j++)
      for (int k = 0; k < c; k++) {
        if (i == j || j == k || k == i) continue;
        ans = min(ans, cost[0][i] + cost[1][j] + cost[2][k]);
      }
  cout << ans << endl;
  return 0;
}
