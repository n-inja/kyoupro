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
  ll p, q, r, a, b, c;
  cin >> p >> q >> r >> a >> b >> c;
  b += a;
  c += b;
  ll npmax = p * a;
  ll npmin = p * a - (p - 1);
  ll nqmax = q * b;
  ll nqmin = q * b - (q - 1);
  ll nrmax = r * c;
  ll nrmin = r * c - (r - 1);
  ll ansmin = max(npmin, max(nqmin, nrmin));
  ll ansmax = min(npmax, min(nqmax, nrmax));
  if (ansmin > ansmax) {
    cout << -1 << endl;
  } else {
    cout << ansmin << " " << ansmax << endl;
  }
  return 0;
}
