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
  ll a, b;
  cin >> a >> b;
  if ((a + b) % 2 == 1) cout << "IMPOSSIBLE" << endl;
  else cout << (a + b) / 2 << endl;
  return 0;
}
