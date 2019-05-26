#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
int n, q;
struct N {
  ll l, r, x, i;
};
struct M {
  ll type, x, i, d;
};

bool operator<(const M &l, const M &r) {
  if (l.x == r.x) {
    return l.type < r.type;
  }
  return l.x < r.x;
}


bool operator<(const N &l, const N &r) { return l.x < r.x; }

vector<N> ps;
vector<ll> d;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n >> q;

  ps.resize(n);
  vector<M> ms(q + n * 2);
  for (int i = 0; i < n; i++) {
    cin >> ps[i].l >> ps[i].r >> ps[i].x;
    ps[i].i = i;
    ms[q + i * 2].d = ps[i].x;
    ms[q + i * 2].type = ps[i].x;
    ms[q + i * 2].x = ps[i].l - ps[i].x;
    ms[q + i * 2].i = i;
    ms[q + i * 2 + 1].d = ps[i].x;
    ms[q + i * 2 + 1].type = -ps[i].x;
    ms[q + i * 2 + 1].i = i;
    ms[q + i * 2 + 1].x = ps[i].r - ps[i].x;
  }
  sort(ps.begin(), ps.end());
  reverse(ps.begin(), ps.end());
  for (int i = 0; i < q; i++) {
    cin >> ms[i].x;
    ms[i].i = i;
    ms[i].d = -1;
    ms[i].type = 101010101010LL;
  }
  sort(ms.begin(), ms.end());
  vector<ll> ans(q);
  map<ll, int> s;
  for (int i = 0; i < ms.size(); i++) {
    if (ms[i].type == 101010101010LL) {
      if (s.size()) {
        ans[ms[i].i] = s.begin()->first;
      } else {
        ans[ms[i].i] = -1;
      }
    } else if (ms[i].type > 0) {
      s[ms[i].d]++;
    } else {
      if (s[ms[i].d] == 1) {
        s.erase(s.find(ms[i].d));
      } else {
        s[ms[i].d]--;
      }
    }
  }
  for (auto &d : ans) cout << d << endl;

  return 0;
}
