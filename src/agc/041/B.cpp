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
  ll n, m, v, p;
  cin >> n >> m >> v >> p;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.rbegin(), a.rend());
  ll ans = 0;
  int l = 0, r = n;
  ll cnt = 0;
  int start = 0;
  for (int i = 0; i < n; i++)
    if (a[i] >= a[p - 1]) {
      ans++;
      l = i;
      if (a[i] > a[p - 1]) {
        start = i + 1;
      }
    }
  int index = l + 1;

  auto f = [&](int i) {
    map<int, ll> mp;
    mp[v - n] = m;
    for (int j = p - 1; j < i; j++) {
      ll b = a[j] - a[i];
      map<int, ll> ump;
      while (b > 0) {
        if (mp.size() == 0) return false;
        auto key = mp.begin()->first;
        if (mp[key] > b) {
          mp[key] -= b;
          if (key < -1) {
            ump[key + 1] += b;
          }
          b = 0;
        } else if (mp[key] == b) {
          if (key < -1) {
            ump[key + 1] += b;
          }
          mp.erase(key);
          b = 0;
        } else {
          if (key < -1) {
            ump[key + 1] += mp[key];
          }
          b -= mp[key];
          mp.erase(key);
        }
      }
      for (auto &it : ump) {
        mp[it.first] += it.second;
      }
    }
    return true;
  };
  while (r - l > 1) {
    int m = (r + l) / 2;
    if (f(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  for (int i = l + 1; i < n; i++) {
    if (a[i] == a[l]) {
      r = i + 1;
    }
  }
  cout << ans + (r - index) << endl;
  return 0;
}
// 1 2 3 3 3 4 5 5 6 6 6 7
