#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
int n, a, b;

int f(int i) {
  string s = to_string(i);
  int ret = 0;
  for (auto &c : s) ret += c - '0';
  return ret;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n >> a >> b;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a <= f(i) && f(i) <= b) ans += i;
  }
  cout << ans << endl;
  return 0;
}
