#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

vector<int> normalize(vector<int> &v) {
  vector<vector<int>> w;
  w.push_back(v);
  vector<int> next(4);
  for (int k = 0; k < 3; k++) {
    for (int j = 0; j < 4; j++) next[j] = w.back()[(j + 1) % 4];
    w.push_back(next);
  }
  sort(w.begin(), w.end());
  return w[0];
}

ll comb(ll n, ll k) {
  if (k == 1) {
    return n;
  } else if (k == 2) {
    return n * (n - 1);
  } else if (k == 3) {
    return n * (n - 1) * (n - 2);
  } else {
    return n * (n - 1) * (n - 2) * (n - 3);
  }
}

int weight(vector<int> v) {
  if (v[0] == v[1] && v[1] == v[2] && v[2] == v[3]) return 4;
  if (v[0] == v[2] && v[1] == v[3]) return 2;
  return 1;
}

ll po(ll e, ll x) {
  if (x == 1) return e;
  if (x == 2) return e * e;
  return e * e * e * e;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> c(n);
  map<vector<int>, int> mp;

  for (int i = 0; i < n; i++) {
    vector<int> v(4);
    for (int j = 0; j < 4; j++) cin >> v[j];
    auto w = normalize(v);

    mp[w]++;
    c[i] = w;
  }
  ll ans = 0;

  for (int i = 0; i < n; i++) {
    mp[c[i]]--;
    for (int j = i + 1; j < n; j++) {
      mp[c[j]]--;
      for (int k = 0; k < 4; k++) {
        map<vector<int>, int> want;
        for (int l = 0; l < 4; l++) {
          vector<int> side(4);
          side[0] = c[i][(l + k) % 4];
          side[1] = c[i][(l + k + 1) % 4];
          side[2] = c[j][(3 - l)];
          side[3] = c[j][(4 - l) % 4];
          reverse(side.begin(), side.end());
          want[normalize(side)]++;
        }

        ll tmp = 1;
        for (auto &pr : want) {
          tmp *= comb(mp[pr.first], pr.second) * po(weight(pr.first), pr.second);
        }
        ans += tmp;
      }
      mp[c[j]]++;
    }
    mp[c[i]]++;
  }

  cout << ans / 3 << endl;
  return 0;
}
