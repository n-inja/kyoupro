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
  vector<ll> d(n);
  for (int i = 0; i < n; i++) cin >> d[i];
  ll ans = 0;
  for (int i = 0; i < n; i++) for (int j = 0; j < i; j++) ans += d[i] * d[j];
  cout << ans << endl;
  return 0;
}
