#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

vector<vector<pair<int, ll>>> p;
vector<pair<ll, ll>> cost;
struct N {
  int now, k;
  ll d;
};
bool operator<(const N &l, const N &r) { return l.d < r.d; }

bool us[1010][1010] = {0};
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  p.resize(n);
  cost.resize(n);
  for (int i = 0; i < m; i++) {
    int s, t;
    ll c;
    cin >> s >> t >> c;
    s--;
    t--;
    p[s].emplace_back(t, c);
    p[t].emplace_back(s, c);
  }
  bool ok = false;
  for (int i = 0; i < n; i++) {
    cin >> cost[i].first >> cost[i].second;
    if (cost[i].first > 0)
      ok = true;
  }
  if (!ok) {
    cout << -1 << endl;
    return 0;
  }
  multiset<N> q;
  q.insert(N{n - 1, 0, 0});
  vll dist(n);
  vector<bool> used(n);
  while (q.size()) {
    N now = *q.begin();
    q.erase(q.begin());
    if (used[now.now])
      continue;
    used[now.now] = true;
    dist[now.now] = now.d;
    for (auto &v : p[now.now]) {
      if (used[v.first])
        continue;
      q.insert(N{v.first, 0, now.d + v.second});
    }
  }
  if (!used[0]) {
    cout << -1 << endl;
    return 0;
  }

  ll ans = 100000000000000LL;
  q.insert(N{0, 0, 0});
  while (q.size()) {
    N now = *q.begin();
    q.erase(q.begin());
    if (us[now.now][now.k])
      continue;
    us[now.now][now.k] = true;
    if (now.d > ans) {
      break;
    }
    if (cost[now.now].first > 0) {
      ll a = (k - now.k + cost[now.now].first - 1) / cost[now.now].first;
      ans = min(ans, now.d + a * cost[now.now].second + dist[now.now]);
    }
    for (int i = 0; now.k + i * cost[now.now].first < k; i++) {
      int kdiff = i * cost[now.now].first;
      ll ddiff = i * cost[now.now].second;
      for (auto &v : p[now.now]) {
        if (us[v.first][now.k + kdiff])
          continue;
        q.insert(N{v.first, now.k + kdiff, now.d + ddiff + v.second});
      }
      if (cost[now.now].first == 0)
        break;
    }
  }
  if (ans < 100000000000000LL)
    cout << ans << endl;
  else
    cout << -1 << endl;

  return 0;
}
