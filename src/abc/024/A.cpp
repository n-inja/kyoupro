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
  int a, b, c, k, s, t;
  cin >> a >> b >> c >> k >> s >> t;
  if (s + t >= k) {
    cout << a * s + b * t - (s + t) * c << endl;
  } else {
    cout << a * s + b * t << endl;
  }
  return 0;
}
