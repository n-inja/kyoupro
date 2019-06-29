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
  vector<int> p(n);
  for (int i = 0; i < n; i++) cin >> p[i];
  ll ans = 0;
  for (int i = 2; i < n; i++) {
    if (p[i - 1] < p[i] && p[i - 1] > p[i - 2]) ans++;
    if (p[i - 1] > p[i] && p[i - 1] < p[i - 2]) ans++;
  }
  cout << ans << endl;
  return 0;
}
