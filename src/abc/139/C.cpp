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
  vector<ll> h(n);
  for (int i = 0; i < n; i++) cin >> h[n - i - 1];
  int ans = 0;
  int tmp = 0, now = 1000000007;
  for (int i = 0; i < n; i++) {
    if (now <= h[i]) {
      now = h[i];
      tmp++;
      ans = max(ans, tmp);
    } else {
      now = h[i];
      tmp = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
