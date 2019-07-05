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
  ll n, k, m;
  cin >> n >> k >> m;
  map<ll, ll> mp;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      mp[i]++;
      n /= i;
      i--;
    }
  }
  if (n > 1) mp[n]++;

  set<ll> s;
  s.insert(1);
  for (auto &v : mp) {
    set<ll> t;
    for (auto &i : s) {
      ll l = i;
      for (ll j = 0; j < v.second * k; j++) {
        l *= v.first;
        if (l > m) break;
        t.insert(l);
      }
    }

    for (auto &i : t) s.insert(i);
  }

  cout << s.size() << endl;
  return 0;
}
