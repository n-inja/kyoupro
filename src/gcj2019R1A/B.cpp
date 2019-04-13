#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

long long gcd(long long a, long long b) {
  if (a % b == 0)
    return b;
  return gcd(b, a % b);
}

// return (x, y) (a * x + b * y = gcd(a, b))
pair<long long, long long> exeuclid(long long a, long long b) {
  if (b == 0)
    return make_pair(1, 0);
  pair<long long, long long> ret = exeuclid(b, a % b);
  ret.first -= a / b * ret.second;
  return make_pair(ret.second, ret.first);
}

// v := [(modulo, reminder)]
// moduloes should be coprime
long long CRT(vector<pair<long long, long long>> v) {
  long long mod = 1;
  long long ret = 0;
  for (int i = 0; i < v.size(); i++) {
    pair<long long, long long> xy = exeuclid(mod, v[i].first);
    long long M = mod * v[i].first;
    long long l = ((v[i].second * mod) % M) * xy.first;
    l %= M;
    long long r = ((ret * v[i].first) % M) * xy.second;
    r %= M;
    ret = (l + r) % M;
    ret += M;
    ret %= M;
    mod = M;
  }
  return ret;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t, n, m;
  cin >> t >> n >> m;
  for (int q = 0; q < t; q++) {
    vector<pair<ll, ll>> v;
    ll a[7] = {16, 9, 5, 7, 11, 13, 17};
    for (int i = 0; i < 7; i++) {
      cout << a[i];
      for (int j = 0; j < 17; j++)
        cout << " " << a[i];
      cout << endl;
      ll s = 0;
      for (int j = 0; j < 18; j++) {
        int b;
        cin >> b;
        if (b < 0) {
          return 0;
        }
        s += b;
        s %= a[i];
      }
      v.emplace_back(a[i], s);
    }

    cout << CRT(v) << endl;
    int c;
    cin >> c;
    if (c < 0)
      break;
  }
  return 0;
}
