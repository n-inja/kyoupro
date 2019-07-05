#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll INF = 1010101010101010LL;
vector<vector<pair<int, ll>>> ps;

struct N {
  ll i, d;

  N(int i, ll d) : i(i), d(d) {}
};

bool operator<(const N &l, const N &r) {
  return l.d > r.d;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n, m, p, q, t;
  cin >> n >> m >> p >> q >> t;
  p--;
  q--;

  vector<vector<ll>> cost(n, vector<ll>(n, INF));
  ps.resize(n);

  for (int i = 0; i < m; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    ps[a].emplace_back(b, c);
    ps[b].emplace_back(a, c);
  }

  priority_queue<N> queue;
  set<int> s;
  s.insert(0);
  s.insert(p);
  s.insert(q);
  for (auto &i : s) {
    queue.emplace(i, 0);
    while (queue.size()) {
      auto v = queue.top();
      queue.pop();
      if (cost[i][v.i] < INF) continue;
      cost[i][v.i] = v.d;
      for (auto &path : ps[v.i]) {
        if (cost[i][path.first] < INF) continue;
        queue.emplace(path.first, v.d + path.second);
      }
    }
  }

  ll ans = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ll pcost = cost[p][i] + cost[p][j];
      ll qcost = cost[q][i] + cost[q][j];
      ll ijcost = cost[0][i] + cost[0][j];
      if (max(pcost, qcost) + ijcost <= t) {
        ans = max(ans, t - max(pcost, qcost));
      }
      if (ijcost + pcost + qcost <= t) ans = t;
    }
  }

  if (cost[0][p] + cost[p][q] + cost[q][0] <= t) ans = t;

  cout << ans << endl;

  return 0;
}
