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
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n - 1);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n - 1; i++) cin >> c[i];
  ll ans = 0;
  int bef = -1;
  for (int i = 0; i < n; i++) {
    if (bef + 2 == a[i]) {
      ans += c[a[i] - 2];
    }
    ans += b[a[i] - 1];
    bef = a[i] - 1;
  }
  cout << ans << endl;
  return 0;
}
