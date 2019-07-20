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
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ll ans = 0;
  for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) ans = max(ans, abs(a[i] - a[j]));
  cout << ans << endl;
  return 0;
}
