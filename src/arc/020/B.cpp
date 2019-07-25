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
  int n, c;
  cin >> n >> c;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll ans = 1010101010;
  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 10; j++) {
      if (i == j) continue;
      ll diff = 0;
      for (int k = 0; k < n; k++) diff += a[k] != ((k % 2 == 1) ? i : j);
      ans = min(ans, diff);
    }
  cout << ans * c << endl;
  return 0;
}
