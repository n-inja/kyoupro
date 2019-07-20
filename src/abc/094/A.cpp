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
  int a, b, x;
  cin >> a >> b >> x;
  if (a <= x && a + b >= x) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
