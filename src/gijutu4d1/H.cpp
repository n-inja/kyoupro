#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

struct N {
  int to;
  ll c, d;
};
struct Node {
  int now;
  ll d;
};

bool operator<(const Node &l, const Node &r) {
  return l.d > r.d;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  ll k;
  cin >> n >> m >> k;
  vector<ll> t(n);
  for (int i = 1; i < n - 1; i++) cin >> t[i];
  vector<vector<N>> p(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    ll c, d;
    cin >> a >> b >> c >> d;
    a--;
    b--;
    p[a].push_back(N{b, c, d});
    p[b].push_back(N{a, c, d});
  }
  priority_queue<Node> q;
  q.push(Node{0, 0});
  vector<ll> vis(n, -1);
  while (q.size()) {
    Node now = q.top();
    q.pop();
    if (vis[now.now] >= 0 && vis[now.now] < now.d) continue;
    vis[now.now] = now.d;
    if (now.d > k) {
      continue;
    }
    if (now.now == n - 1) {
      cout << now.d << endl;
      return 0;
    }
    for (auto &v : p[now.now]) {
      ll r = (v.d - now.d % v.d) % v.d;
      Node next{v.to, r + now.d + t[v.to] + v.c};
      if (vis[v.to] >= 0 && vis[v.to] < next.d) continue;
      vis[v.to] = next.d;
      q.push(next);
    }
  }
  cout << -1 << endl;
  return 0;
}
