#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

bool f(int m, int d1, int d10) {
  if (d1 >= 2 && d10 >= 2 && d1 * d10 == m) return true;
  return false;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int m, d;
  cin >> m >> d;
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= d; j++) {
      if (f(i, j % 10, j / 10)) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
