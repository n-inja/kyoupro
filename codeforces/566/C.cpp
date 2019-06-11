#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

struct N {
  string s;
  int num, i;
  char last;
  bool used;
};

bool operator<(const N &l, const N &r) {
  if (l.num == r.num) return l.last < r.last;
  return l.num > r.num;
}

bool ok(N &l, N &r) {
  return (l.num == r.num);
}

bool ok2(N &l, N &r) {
  return (l.num == r.num && l.last == r.last);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<N> s(n);
  for (int i = 0; i < n; i++) cin >> s[i].s;
  for (int i = 0; i < n; i++) {
    for (auto &c : s[i].s)
      if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
        s[i].num++;
        s[i].last = c;
      }
  }

  sort(s.begin(), s.end());

  vector<N> t;
  vector<pair<int, int>> ps, ps2;
  for (int i = 0; i < n; i++) s[i].i = i;
  for (int i = 0; i < n - 1; i++) {
    if (ok2(s[i], s[i + 1])) {
      s[i].used = true;
      s[i + 1].used = true;
      ps.emplace_back(i, i + 1);
      i++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (!s[i].used) t.push_back(s[i]);
  }
  for (int i = 1; i < t.size(); i++) {
    if (ok(t[i - 1], t[i])) {
      ps2.emplace_back(t[i - 1].i, t[i].i);
      i++;
    }
  }
  int m = min(ps.size(), ps2.size());
  if (m < ps.size()) {
    int d = (ps.size() - m) / 2;
    m += d;
    for (int i = m; i < m + d; i++) ps2.push_back(ps[i]);
  }
  cout << m << endl;
  for (int i = 0; i < m; i++) {
    cout << s[ps2[i].first].s << " " << s[ps[i].first].s << endl;
    cout << s[ps2[i].second].s << " " << s[ps[i].second].s << endl;
  }

  return 0;
}
