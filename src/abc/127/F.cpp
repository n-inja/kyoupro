#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;


class BIT {
public:
  int n;
  vector<int> bit;

  BIT(int n_) {
    n = 1;
    while (n < n_) {
      n <<= 1;
    }
    bit.resize(n + 1);
  }

  // add v[a] + w
  void add(int a, int w) {
    a++;
    if (a == 0 || a > n)
      return;
    for (int x = a; x <= n; x += x & -x)
      bit[x] += w;
  }

  // [0, a)
  int sum(int a) {
    if (a == 0)
      return 0;
    int ret = 0;
    for (int x = a; x > 0; x -= x & -x)
      ret += bit[x];
    return ret;
  }
};

BIT r(202020);

struct N {
  ll c, a, b, val;
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<N> ns(n);
  int last = -1;
  for (int i = 0; i < n; i++) {
    cin >> ns[i].c;
    if (ns[i].c == 1) {
      cin >> ns[i].a >> ns[i].b;
    } else {
    }
  }
  map<ll, int> mp;
  for (int i = 0; i < n; i++) {
    if (ns[i].c == 1) {
      mp[ns[i].a] = 0;
    }
  }
  int c = 0;
  vector<ll> inv(201010);
  for (auto &v : mp) {
    inv[c] = v.first;
    v.second = c++;
  }

  vector<ll> v;
  c = 0;
  ll base = 0;
  ll lnum = 0, rnum = 0, now = 0, x = 0, val = 0;
  map<ll, int> num;
  for (int i = 0; i < n; i++) {
    if (ns[i].c == 1) {
      r.add(mp[ns[i].a], 1);
      c++;
      base += ns[i].b;
      v.push_back(ns[i].a);
      num[ns[i].a]++;
      if (i == 0) {
        lnum = 0;
        rnum = 0;
        now = 1;
        x = ns[i].a;
        val = 0;
      } else {
        if (ns[i].a < x) {
          lnum++;
        } else if (ns[i].a == x) {
          now++;
        } else {
          rnum++;
        }
        val += abs(x - ns[i].a);
      }
    } else {

      ll li = 0, ri = 202020;
      ll aim = (c + 1) / 2;
      while (ri - li > 1) {
        ll m = (li + ri) / 2;
        if (r.sum(m) >= aim) {
          ri = m;
        } else {
          li = m;
        }
      }
      ll a = inv[li];
      if (a < x) {
        auto it = num.find(x);
        while (true) {
          if (it->first == a) break;
          it--;
          val -= lnum * abs(it->first - x);
          val += now * abs(it->first - x);
          val += rnum * abs(it->first - x);
          lnum -= it->second;
          rnum += now;
          now = it->second;
          x = it->first;
        }
        cout << a << " " << base + val << endl;
      } else if (a > x) {
        auto it = num.find(x);
        while (true) {
          if (it->first == a) break;
          it++;
          val -= rnum * abs(it->first - x);
          val += now * abs(it->first - x);
          val += lnum * abs(it->first - x);
          rnum -= it->second;
          lnum += now;
          now = it->second;
          x = it->first;
        }
        cout << a << " " << base + val << endl;
      } else {
        cout << a << " " << base + val << endl;
      }
    }
  }

  return 0;
}
