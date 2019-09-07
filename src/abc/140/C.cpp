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
  vector<int> b(n - 1);
  ll ans = 0;
  for (int i = 0; i < n - 1; i++) cin >> b[i];
  ans += b.front() + b.back();
  for (int i = 0; i < n - 2; i++) ans += min(b[i], b[i + 1]);
  cout << ans << endl;
  return 0;
}
