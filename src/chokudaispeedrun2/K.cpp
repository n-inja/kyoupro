#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

#include <iostream>
#include <vector>

using namespace std;

class U {
public:
  int n;
  vector<int> p, s, s2;

  U(int _) {
    n = _;
    p.resize(n);
    s.resize(n);
    s2.resize(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
      s[i] = 1;
      s2[i] = 0;
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
    s2[mi] = max(s2[mi], s2[ma]);
    s[ma] = 0;
    s2[ma] = 0;
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

  void set(int i) {
    s2[parent(i)] = 1;
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

  int n;
  cin >> n;
  vector<int> a(n), b(n);
  map<int, int> mp;
  int c = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    if (mp.find(a[i]) == mp.end()) {
      mp[a[i]] = c++;
    }
    if (mp.find(b[i]) == mp.end()) {
      mp[b[i]] = c++;
    }
  }
  U u(c);
  for (int i = 0; i < n; i++) {
    if (u.connect(mp[a[i]], mp[b[i]])) {
      u.set(mp[a[i]]);
    }
  }

  int ans = 0;
  for (int i = 0; i < c; i++) {
    if (u.s[i] > 0)
      ans += u.s[i] + u.s2[i] - 1;
  }
  cout << ans << endl;
  return 0;
}
