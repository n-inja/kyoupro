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
  vector<bool> ok(100000);
  for (int i = 0; i * i < 100000; i++) ok[i * i] = true;
  int n, d;
  cin >> n >> d;
  vector<vector<int>> x(n, vector<int>(d));
  for (int i = 0; i < n; i++) for (int j = 0; j < d; j++) cin >> x[i][j];
  ll ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      ll sum = 0;
      for (int k = 0; k < d; k++) sum += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
      if (ok[sum]) ans++;
    }
  cout << ans << endl;
  return 0;
}
