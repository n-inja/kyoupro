#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

struct N {
  ll a, b, c;
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int x, y, z;
  cin >> x >> y >> z;
  int n = x + y + z;
  vector<N> ns(n);
  for (int i = 0; i < n; i++)
    cin >> ns[i].a >> ns[i].b >> ns[i].c;
  sort(ns.begin(), ns.end(),
       [](const N &l, const N &r) { return l.a - l.b < r.a - r.b; });
  ll lsum = 0, rsum = 0, lssm = 0, rssm = 0;
  multiset<ll> ls, rs, lunused, runused;
  for (int i = 0; i < y; i++) {
    lsum += ns[i].b;
    lunused.insert(ns[i].b - ns[i].c);
  }
  for (int i = y; i < n; i++) {
    rsum += ns[i].a;
    rs.insert(ns[i].c - ns[i].a);
  }
  while (rs.size() > z) {
    runused.insert(-*rs.begin());
    rs.erase(rs.begin());
  }
  for (auto &i : rs) {
    rssm += i;
  }

  ll ans = lsum + rsum + lssm + rssm;

  for (int k = y; k < n - x; k++) {
    lsum += ns[k].b;
    rsum -= ns[k].a;
    if (rs.find(ns[k].c - ns[k].a) != rs.end()) {
      rs.erase(rs.find(ns[k].c - ns[k].a));
      rssm -= ns[k].c - ns[k].a;
    } else {
      rssm -= *rs.begin();
      rs.erase(rs.begin());
    }
    lunused.insert(ns[k].b - ns[k].c);
    lssm += -*lunused.begin();
    ls.insert(-*lunused.begin());
    lunused.erase(lunused.begin());
    ans = max(ans, lsum + rsum + lssm + rssm);
  }
  cout << ans << endl;
  return 0;
}
