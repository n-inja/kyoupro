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
  ll n;
  cin >> n;
  ll po[20] = {0};
  po[0] = 1;
  for (int i = 1; i < 19; i++) po[i] = 10 * po[i - 1];

  auto ok = [&](ll n) {
    if (n < 0) return false;
    string s = to_string(n);
    for (int i = s.size() - 1; i >= 2; i--) {
      ll d = n / (po[i] + 1);
      n -= d * (po[i] + 1);
    }
    return n == 0;
  };
  auto f = [&](ll n) {
    string s = to_string(n);
    ll ret = 0;
    for (int i = s.size() - 1; i >= 2; i--) {
      ll d = n / (po[i] + 1);
      n -= d * (po[i] + 1);
      ret += d * po[i];
    }
    return ret;
  };

  vector<ll> ans;
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++) {
      if (ok(n - 2 * i - 11 * j)) {
        ans.push_back(f(n - 2 * i - j * 11) + i + 10 * j);
      }
    }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (auto &a : ans) cout << a << endl;
  return 0;
}
