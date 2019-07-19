#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

vector<ll> b;

string solve(ll x, ll y) {
  ll u = x + y;
  ll v = x - y;
  string ret;

  string dir = "LDUR";
  for (int i = 30; i >= 0; i--) {
    int j = 0;
    if (u < 0) {
      j += 0;
      u += b[i];
    } else {
      j += 2;
      u -= b[i];
    }
    if (v < 0) {
      j += 0;
      v += b[i];
    } else {
      j += 1;
      v -= b[i];
    }
    ret.push_back(dir[j]);
  }
  reverse(ret.begin(), ret.end());

  return ret;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  b.resize(31);
  b[0] = 1;
  for (int i = 0; i < 30; i++) b[i + 1] = b[i] * 2;
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    mp[abs(x[i] + y[i]) % 2]++;
  }
  if (mp[0] != n && mp[0] != 0) {
    cout << -1 << endl;
    return 0;
  }
  if (mp[0] > 0) {
    cout << 32 << endl;
    ll m = 1;
    cout << 1;
    for (int i = 0; i < 31; i++) {
      cout << " " << m;
      m <<= 1;
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
      cout << "R";
      cout << solve(x[i] - 1, y[i]) << endl;
    }
  } else {
    cout << 31 << endl;
    ll m = 2;
    cout << 1;
    for (int i = 0; i < 30; i++) {
      cout << " " << m;
      m <<= 1;
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
      cout << solve(x[i], y[i]) << endl;
    }
  }

  return 0;
}
