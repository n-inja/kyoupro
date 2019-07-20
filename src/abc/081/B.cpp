#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll f(int x) {
  int r = 0;
  while (x && (x & 1) == 0) {
    r++;
    x >>= 1;
  }
  return r;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  ll ans = 101010101;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ans = min(ans, f(x));
  }
  cout << ans << endl;
  return 0;
}
