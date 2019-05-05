#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int n;
string s, t;
bool f(ll sx, ll w, char back, char next) {
  ll ngl = sx, ngr = sx;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (s[i] == next) {
      ngr += 1;
    } else if (s[i] == back) {
      ngl -= 1;
    }
    if (ngr > w || ngl < 1) {
      ok = false;
    }
    if (t[i] == next) {
      ngl += 1;
    } else if (t[i] == back) {
      ngr -= 1;
    }
    ngr = max(ngr, 1LL);
    ngl = min(ngl, w);
    if (ngr > w || ngl < 1) {
      ok = false;
    }
  }
  return ok;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int h, w, sx, sy;
  cin >> h >> w >> n >> sy >> sx;
  cin >> s >> t;
  if (f(sx, w, 'L', 'R') && f(sy, h, 'U', 'D')) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
