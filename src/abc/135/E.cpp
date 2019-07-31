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
  ll k, x, y;
  cin >> k >> x >> y;
  bool xf = x < 0;
  bool yf = y < 0;
  x = abs(x);
  y = abs(y);

  vector<pair<ll, ll>> ans;
  if (k % 2 == 0 && (x + y) % 2 == 1) {
    cout << -1 << endl;
    return 0;
  }

  auto dist = [](ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) + abs(y1 - y2);
  };
  using pii = pair<ll, ll>;
  auto cross = [](ll x, ll y, ll z, ll a) {
    return x * z + y * a;
  };
  auto intersec = [](pii x1, pii y1, pii x2, pii y2) {
    pii v1(y1.first - x1.first, y1.second - x1.second);
    pii v2(y2.first - x2.first, y2.second - x2.second);
    pii nx1(min(x1.first + x1.second, y1.first + y1.second), min(x1.first - x1.second, y1.first - y1.second));
    pii ny1(max(x1.first + x1.second, y1.first + y1.second), max(x1.first - x1.second, y1.first - y1.second));
    pii nx2(min(x2.first + x2.second, y2.first + y2.second), min(x2.first - x2.second, y2.first - y2.second));
    pii ny2(max(x2.first + x2.second, y2.first + y2.second), max(x2.first - x2.second, y2.first - y2.second));
    if (v1.first * v1.second == v2.first * v2.second) {
      if (nx1.first == ny1.first && nx1.first == nx2.first) {
        if (nx1.second <= nx2.second && nx2.second <= ny1.second) {
          return make_pair(true, make_pair((nx2.first + nx2.second) / 2, (nx2.first - nx2.second) / 2));
        }
        if (nx1.second <= ny2.second && ny2.second <= ny1.second) {
          return make_pair(true, make_pair((ny2.first + ny2.second) / 2, (ny2.first - ny2.second) / 2));
        }
      }
      if (nx1.second == ny1.second && nx1.second == nx2.second) {
        if (nx1.first <= nx2.first && nx2.first <= ny1.first) {
          return make_pair(true, make_pair((nx2.first + nx2.second) / 2, (nx2.first - nx2.second) / 2));
        }
        if (nx1.first <= ny2.first && ny2.first <= ny1.first) {
          return make_pair(true, make_pair((ny2.first + ny2.second) / 2, (ny2.first - ny2.second) / 2));
        }
      }
    } else {
      if (nx1.first <= nx2.first && nx2.first <= ny1.first && nx2.second <= nx1.second && nx1.second <= ny2.second) {
        // (nx2.first, nx1.second)
        return make_pair(true, make_pair((nx2.first + nx1.second) / 2, (nx2.first - nx1.second) / 2));
      }
      if (nx1.second <= nx2.second && nx2.second <= ny1.second && nx2.first <= nx1.first && nx1.first <= ny2.first) {
        // (nx1.first, nx2.second)
        return make_pair(true, make_pair((nx1.first + nx2.second) / 2, (nx1.first - nx2.second) / 2));
      }
    }
    return make_pair(false, make_pair(0LL, 0LL));
  };
  function<void(ll, ll)> f;
  f = [&](ll i, ll j) {
    if (dist(i, j, x, y) == 0) {
      return;
    }
    if (dist(i, j, x, y) == k) {
      ans.emplace_back(x, y);
      return;
    }
    if (dist(i, j, x, y) >= 2 * k) {
      ll dx = x - i;
      ll dy = y - j;
      if (abs(dx) >= k) {
        ans.emplace_back(i + min(k, max(-k, dx)), j);
        f(i + min(k, max(-k, dx)), j);
      } else {
        ans.emplace_back(i, j + min(k, max(-k, dy)));
        f(i, j + min(k, max(-k, dy)));
      }
      return;
    }
    if (k % 2 == 1 && dist(i, j, x, y) % 2 == 1) {
      if (dist(i + k, j, x, y) <= 2 * k) {
        ans.emplace_back(i + k, j);
        f(i + k, j);
        return;
      }
      if (dist(i - k, j, x, y) <= 2 * k) {
        ans.emplace_back(i - k, j);
        f(i - k, j);
        return;
      }
      if (dist(i, j + k, x, y) <= 2 * k) {
        ans.emplace_back(i, j + k);
        f(i, j + k);
        return;
      }
      if (dist(i, j - k, x, y) <= 2 * k) {
        ans.emplace_back(i, j - k);
        f(i, j - k);
        return;
      }

    }
    vector<pair<ll, ll>> ps({
                                make_pair(i + k, j),
                                make_pair(i, j + k),
                                make_pair(i - k, j),
                                make_pair(i, j - k),
                            }), qs({
                                       make_pair(x + k, y),
                                       make_pair(x, y + k),
                                       make_pair(x - k, y),
                                       make_pair(x, y - k),
                                   });
    for (int k = 0; k < 4; k++)
      for (int l = 0; l < 4; l++) {
        auto v = intersec(ps[k], ps[(k + 1) % 4], qs[l], qs[(l + 1) % 4]);
        if (v.first) {
          ans.push_back(v.second);
          f(v.second.first, v.second.second);
          return;
        }
      }
  };
  f(0, 0);

  cout << ans.size() << endl;
  for (auto &v : ans) {
    if (xf) v.first = -v.first;
    if (yf) v.second = -v.second;
    cout << v.first << " " << v.second << endl;
  }

  return 0;
}
