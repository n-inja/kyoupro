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
  int n, s, t;
  cin >> n >> s >> t;
  int w;
  cin >> w;
  int ans = 0;
  if (s <= w && w <= t) ans++;
  for (int i = 0; i < n - 1; i++) {
    int a;
    cin >> a;
    w += a;
    if (s <= w && w <= t) ans++;
  }
  cout << ans << endl;
  return 0;
}
