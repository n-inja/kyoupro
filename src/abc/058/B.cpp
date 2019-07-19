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
  int w, a, b;
  cin >> w >> a >> b;
  cout << max(max(b - (a + w), a - (b + w)), 0) << endl;
  return 0;
}
