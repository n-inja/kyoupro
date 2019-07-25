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
  ll y, m, d;
  cin >> y >> m >> d;
  if (m == 1 || m == 2) {
    y--;
    m = 12 + m;
  }
  cout << 735369 - (365 * y + y / 4 - y / 100 + y / 400 + (306 * (m + 1)) / 10 + d - 429) << endl;
  return 0;
}
