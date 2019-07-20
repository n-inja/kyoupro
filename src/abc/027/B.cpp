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
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int sum = 0;
  for (int i = 0; i < n; i++) sum += a[i];
  if (sum % n != 0) {
    cout << -1 << endl;
    return 0;
  }
  int p = sum / n;
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] != p) {
      ans++;
      a[i + 1] += a[i] - p;
      a[i] = p;
    }
  }
  cout << ans << endl;
  return 0;
}
