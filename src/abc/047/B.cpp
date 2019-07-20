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
  vector<int> l, r, u, d;
  int n, w, h;
  cin >> w >> h >> n;
  l.push_back(0);
  r.push_back(w);
  u.push_back(0);
  d.push_back(h);
  for (int i = 0; i < n; i++) {
    int x, y, a;
    cin >> x >> y >> a;
    if (a == 1) {
      l.push_back(x);
    } else if (a == 2) {
      r.push_back(x);
    } else if (a == 3) {
      u.push_back(y);
    } else {
      d.push_back(y);
    }
  }
  cout << max(0, *min_element(r.begin(), r.end()) - *max_element(l.begin(), l.end())) *
          max(0, *min_element(d.begin(), d.end()) - *max_element(u.begin(), u.end())) << endl;

  return 0;
}
