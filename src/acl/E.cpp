#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll P = 998244353;

struct range {
  ll l, r, v, sum;
};

bool operator<(const range &a, const range &b) {
  if (a.l == b.l) {
    if (a.r == b.r) {
      return a.v < b.v;
    }
    return a.r < b.r;
  }
  return a.l < b.l;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  set<range> rs;
  vector<ll> s(n + 1, 0);
  s[0] = 0;
  ll val = 1;
  for (int i = 0; i < n; i++) {
    s[i + 1] = (s[i] + val) % P;
    val = (val * 10) % P;
  }
  rs.insert(range{0, n, 1, s[n]});
  ll ans = s[n];
  for (int i = 0; i < q; i++) {
    ll l_, r_, v;
    cin >> l_ >> r_ >> v;
    ll l = n - r_;
    ll r = n - l_;
    r++;
    auto it = rs.lower_bound(range{l, r, v, 0LL});
    while (it != rs.end() && r > it->l) {
      if (it->l < l && it->r > r) {
        ans = (ans + P - it->sum) % P;
        range new_r = *it;
        range new_r2 = *it;
        new_r.sum = (new_r.sum + P - ((s[r] - s[new_r.l]) * new_r.v) % P) % P;
        new_r2.sum = (new_r2.sum + P - ((s[new_r2.r] - s[l]) * new_r2.v) % P) % P;
        ans = (ans + new_r.sum) % P;
        ans = (ans + new_r2.sum) % P;
        rs.erase(it);
        rs.insert(new_r);
        rs.insert(new_r2);
      } else if (it->r > r) {
        range new_r = *it;
        ans = (ans + P - new_r.sum) % P;
        new_r.sum = (new_r.sum + P - ((s[r] - s[new_r.l]) * new_r.v) % P) % P;
        ans = (ans + new_r.sum) % P;
        new_r.l = r;
        rs.erase(it);
        rs.insert(new_r);
      } else {
        ans = (ans + P - it->sum) % P;
        rs.erase(it);
      }
      it = rs.lower_bound(range{l, r, v, 0LL});
    }
    it = rs.lower_bound(range{l, r, v, 0LL});
    if (it != rs.begin()) {
      it--;
      while (it != rs.end() && l < it->r) {
        if (it->l < l && it->r > r) {
          ans = (ans + P - it->sum) % P;
          range new_r = *it;
          range new_r2 = *it;
          new_r.sum = (new_r.sum + P - ((s[r] - s[new_r.l]) * new_r.v) % P) % P;
          new_r.l = r;
          new_r2.sum = (new_r2.sum + P - ((s[new_r2.r] - s[l]) * new_r2.v) % P) % P;
          new_r2.r = l;
          ans = (ans + new_r.sum) % P;
          ans = (ans + new_r2.sum) % P;
          rs.erase(it);
          rs.insert(new_r);
          rs.insert(new_r2);
        } else if (it->l < l) {
          range new_r = *it;
          ans = (ans + P - new_r.sum) % P;
          new_r.sum = (new_r.sum + P - ((s[new_r.r] - s[l]) * new_r.v) % P) % P;
          ans = (ans + new_r.sum) % P;
          new_r.r = l;
          rs.erase(it);
          rs.insert(new_r);
        } else {
          ans = (ans + P - it->sum) % P;
          rs.erase(it);
        }
        it = rs.lower_bound(range{l, r, v, 0LL});
        if (it == rs.begin()) break;
        it--;
      }
    }
    range new_r{l, r, v, (((P + s[r] - s[l]) % P) * v) % P};
    cout << (ans + new_r.sum) % P << endl;
    ans = (ans + new_r.sum) % P;
    rs.insert(new_r);
  }
  return 0;
}
