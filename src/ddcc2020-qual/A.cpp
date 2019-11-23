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
  int x, y;
  cin >> x >> y;
  ll ans = 0;
  if (x == 1 && y == 1) {
    ans += 400000;
  }
  if (x == 1) {
    ans += 300000;
  } else if (x == 2) {
    ans += 200000;
  } else if (x == 3) {
    ans += 100000;
  }
  if (y == 1) {
    ans += 300000;
  } else if (y == 2) {
    ans += 200000;
  } else if (y == 3) {
    ans += 100000;
  }

  cout << ans << endl;
  return 0;
}
