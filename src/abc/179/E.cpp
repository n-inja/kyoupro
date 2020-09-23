#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector <vector<int>>;
using vvl = vector <vector<ll>>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n, x, m;
  cin >> n >> x >> m;
  vector <ll> as(m + 1);
  map<ll, int> s;
  as[0] = x;
  s[x] = 0;
  int len = 0;
  int st = 0;
  ll sum = as[0];
  ll ans = as[0];
  n--;
  for (int i = 0; i < m && n > 0; i++) {
    as[i + 1] = (as[i] * as[i]) % m;
    if (s.find(as[i + 1]) != s.end()) {
      len = i + 1 - s[as[i + 1]];
      for (int j = 0; j < s[as[i + 1]]; j++) sum -= as[j];
      st = s[as[i + 1]];
      break;
    }
    ans += as[i + 1];
    n--;
    sum += as[i + 1];
    s[as[i + 1]] = i + 1;
  }
  if (n > 0) {
    ans += (n / len) * sum;
    for (int j = 0; j < (n % len); j++) {
      ans += as[st + j];
    }
  }
  cout << ans << endl;
  return 0;
}