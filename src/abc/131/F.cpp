#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;


class U {
public:
  int n;
  vector<int> p, s;

  U(int _) {
    n = _;
    p.resize(n);
    s.resize(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
      s[i] = 1;
    }
  }

  bool connect(int a, int b) {
    int ap, bp;
    for (ap = p[a]; ap != p[ap]; ap = p[ap]);
    for (bp = p[b]; bp != p[bp]; bp = p[bp]);
    if (ap == bp)
      return true;
    int mi = min(ap, bp), ma = max(ap, bp);
    p[ma] = mi;
    s[mi] += s[ma];
    s[ma] = 0;
    for (int pp = a; pp != mi;) {
      int next = p[pp];
      p[pp] = mi;
      pp = next;
    }
    for (int pp = b; pp != mi;) {
      int next = p[pp];
      p[pp] = mi;
      pp = next;
    }
    return false;
  }

  int q(int a) {
    int ap;
    for (ap = a; ap != p[ap]; ap = p[ap]);
    return s[ap];
  }

  int parent(int a) {
    int ap;
    for (ap = a; ap != p[ap]; ap = p[ap]);
    return p[ap];
  }

  bool query(int a, int b) { return parent(a) == parent(b); }
};

U u(101010);

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<ll, ll>> ps(n);
  for (int i = 0; i < n; i++) cin >> ps[i].first >> ps[i].second;

  sort(ps.begin(), ps.end());

  vector<int> buf;
  buf.push_back(ps[0].second);
  for (int i = 1; i < n; i++) {
    if (ps[i].first == ps[i - 1].first) {
      buf.push_back(ps[i].second);
    } else {
      int now = buf[0];
      for (int j = 1; j < buf.size(); j++) {
        u.connect(now, buf[j]);
      }
      buf.clear();
      buf.push_back(ps[i].second);
    }
  }
  int now = buf[0];
  for (int j = 1; j < buf.size(); j++) {
    u.connect(now, buf[j]);
  }
  ll ans = 0;
  vector<set<int>> q(101010);
  for (int i = 0; i < n; i++) {
    q[u.parent(ps[i].second)].insert(ps[i].first);
  }
  for (int i = 0; i <= 100000; i++) {
    if (u.parent(i) == i)
      ans += q[i].size() * u.s[i];
  }
  ans -= n;
  cout << ans << endl;

  return 0;
}
