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
  ll h, w, x, y;
  cin >> w >> h >> x >> y;
  if (x * 2 == w && y * 2 == h)
    printf("%.9lf 1\n", (double) h * w / 2);
  else
    printf("%.9lf 0\n", (double) h * w / 2);

  return 0;
}
