#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
ll P = 1000000007;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll ans = 1;
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> c(n);
  c[0] = 3;
  for (int i = 0; i < n; i++) {
    if (c[a[i]] == 0) {
      ans = 0;
      break;
    } else {
      ans *= c[a[i]];
      ans %= P;
      c[a[i]]--;
      c[a[i] + 1]++;
    }
  }
  cout << ans << endl;
  return 0;
}
