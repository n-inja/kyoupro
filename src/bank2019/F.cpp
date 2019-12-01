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
  ll t1, t2;
  ll a1, a2, b1, b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  if (a1 > b1) {
    swap(a1, b1);
    swap(a2, b2);
  }
  ll mindist = (b1 - a1) * t1;
  ll fix = mindist - (a2 - b2) * t2;
  if (fix > 0) {
    cout << 0 << endl;
    return 0;
  }
  if (fix == 0) {
    cout << "infinity" << endl;
    return 0;
  }
  ll k = (mindist) / (-fix);
  if (k * (-fix) == mindist) {
    cout << 2 * k << endl;
  } else {
    cout << (k * 2 + 1) << endl;
  }
  return 0;
}
