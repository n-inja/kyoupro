#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int n;
vector<ll> x, y;

ll f(ll p, ll q) {
  if (p == 0 && q == 0) return n;
  ll ret = n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i != j) {
        if (x[i] - x[j] == p && y[i] - y[j] == q) ret--;
      }
  return ret;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n;
  x.resize(n);
  y.resize(n);
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  ll ret = 1000000000;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      ret = min(ret, f(x[i] - x[j], y[i] - y[j]));
    }
  cout << ret << endl;
  return 0;
}
