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
  int n, x;
  cin >> n >> x;
  vector<int> l(n);
  for (int i = 0; i < n; i++) cin >> l[i];
  ll ans = 1;
  int now = 0;
  for (int i = 0; i < n; i++) {
    now += l[i];
    if (now <= x) ans++;
  }
  cout << ans << endl;
  return 0;
}
