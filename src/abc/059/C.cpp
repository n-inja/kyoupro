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
  vector<ll> sum(n);
  sum[0] = a[0];
  for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + a[i];
  ll b = 0;

  ll ans1 = 0, ans2 = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      ll c = max(1 - (sum[i] + b), 0LL);
      ans1 += c;
      b += c;
    } else {
      ll c = max((sum[i] + b) + 1, 0LL);
      ans1 += c;
      b -= c;
    }
  }
  b = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 1) {
      ll c = max(1 - (sum[i] + b), 0LL);
      ans2 += c;
      b += c;
    } else {
      ll c = max((sum[i] + b) + 1, 0LL);
      ans2 += c;
      b -= c;
    }
  }
  cout << min(ans1, ans2) << endl;

  return 0;
}
