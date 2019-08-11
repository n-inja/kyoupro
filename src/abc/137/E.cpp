#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll INF = 1 << 29;

struct N {
  int now;
  ll d;
};

bool operator<(const N &l, const N &r) {
  return l.d > r.d;
}

struct M {
  int a, b;
  ll d;
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  ll p;
  cin >> n >> m >> p;
  vector<vector<int>> inv(n), invinv(n);
  vector<M> path;
  for (int i = 0; i < m; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--;
    b--;
    inv[b].push_back(a);
    invinv[a].push_back(b);
    path.push_back(M{a, b, p - c});
  }
  vector<ll> d(n, INF);
  priority_queue<N> q;
  q.push(N{n - 1, 0});
  vector<bool> ok(n), ok2(n);
  while (q.size()) {
    N now = q.top();
    q.pop();
    if (ok[now.now]) continue;
    ok[now.now] = true;
    for (auto &v : inv[now.now]) {
      if (ok[v]) continue;
      q.push(N{v, 0});
    }
  }
  q.push(N{0, 0});
  while (q.size()) {
    N now = q.top();
    q.pop();
    if (ok2[now.now]) continue;
    ok2[now.now] = true;
    for (auto &v : invinv[now.now]) {
      if (ok2[v]) continue;
      q.push(N{v, 0});
    }
  }

  d[0] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (d[path[j].b] > d[path[j].a] + path[j].d) {
        d[path[j].b] = d[path[j].a] + path[j].d;
        if (i == n - 1 && ok[path[j].b] && ok2[path[j].b]) {
          cout << -1 << endl;
          return 0;
        }
      }
    }
  }

  cout << max(0LL, -d[n - 1]) << endl;

  return 0;
}
