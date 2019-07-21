#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll div(ll s) {
  if (s < 0) return 0;
  return 1;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll s;
  cin >> s;
  ll t = sqrt(s);
  if (t * t == s) {
    cout << "0 0 " << t << " 0 0 " << t << endl;
    return 0;
  }
  if (t * t > s) t--;

  ll x1, y1, x2, y2;
  ll LIM = 1000000000LL;

  ll d = div(t * (t + 1) - s);

  if (d != 0) {
    cerr << "a" << endl;
    cout << "0 0 " << t << " " << d << " " << (t * (t + 1) - s) / d << " " << t + 1 << endl;
    return 0;
  }

  d = div((t + 1) * (t + 1) - s);

  if (d != 0) {
    cout << "0 0 " << t + 1 << " " << d << " " << ((t + 1) * (t + 1) - s) / d << " " << t + 1 << endl;
    return 0;
  }

  return 0;
}
