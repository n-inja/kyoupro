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
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> a(n, vector<ll>(m)), b(n, vector<ll>(m));
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> b[i][j];

  ll t = 0;
  for (int i = 0; i < n; i++) {
    ll nt = 1010101010;
    for (int j = 0; j < m; j++) {
      ll r = ((a[i][j] - t) % a[i][j] + a[i][j]) % a[i][j];
      nt = min(nt, t + r + b[i][j]);
    }
    t = nt;
  }
  cout << t << endl;

  return 0;
}
