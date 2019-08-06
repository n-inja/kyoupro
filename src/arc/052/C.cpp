#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

struct N {
  int now, c;
  ll d;
};

bool operator<(const N &l, const N &r) {
  if (l.c == r.c)
    return l.d > r.d;
  return l.c > r.c;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> pa(n), pb(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> c >> a >> b;
    if (c) {
      pb[a].push_back(b);
      pb[b].push_back(a);
    } else {
      pa[a].push_back(b);
      pa[b].push_back(a);
    }
  }
  priority_queue<N> q;
  q.push(N{0, 0, 0});
  vector<vector<bool>> used(n, vector<bool>(n + 2));
  ll INF = 1LL << 40;
  vector<ll> d(n, INF);

  while (q.size()) {
    N now = q.top();
    q.pop();
    if (used[now.now][now.c]) continue;
    used[now.now][now.c] = true;
    d[now.now] = min(d[now.now], now.d);
    for (auto &j : pa[now.now]) {
      if (used[j][now.c]) continue;
      if (d[j] < now.d + 1) continue;
      q.push(N{j, now.c, now.d + 1});
    }
    if (now.c >= n) continue;
    for (auto &j : pb[now.now]) {
      if (used[j][now.c + 1]) continue;
      if (d[j] < now.d + now.c + 1) continue;
      q.push(N{j, now.c + 1, now.d + now.c + 1});
    }
  }
  for (auto &a : d) cout << a << endl;
  return 0;
}
