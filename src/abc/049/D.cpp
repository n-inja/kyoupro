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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k, l;
  cin >> n >> k >> l;
  U u1(n), u2(n);
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    u1.connect(a, b);
  }
  for (int i = 0; i < l; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    u2.connect(a, b);
  }

  map<pair<int, int>, int> mp;
  for (int i = 0; i < n; i++) {
    mp[make_pair(u1.parent(i), u2.parent(i))]++;
  }
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    ans[i] = mp[make_pair(u1.parent(i), u2.parent(i))];
  }

  cout << ans[0];
  for (int i = 1; i < n; i++) cout << " " << ans[i];
  cout << endl;
  return 0;
}
