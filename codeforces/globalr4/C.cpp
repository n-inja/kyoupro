#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll P = 998244353;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll h, w;
  cin >> h >> w;
  ll ans = 4;
  for (int i = 0; i < h - 1; i++) ans = (ans * 2) % P;
  for (int j = 0; j < w - 1; j++) ans = (ans * 2) % P;
  cout << ans << endl;
  return 0;
}
