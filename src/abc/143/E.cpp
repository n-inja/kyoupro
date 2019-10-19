#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
struct N {
  int now;
  ll d;
};

bool operator<(const N &l, const N &r) {
  return l.d > r.d;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll l;
  int n, m;
  cin >> n >> m >> l;
  vector<bitset<300>> v(n);
  vector<vector<pair<int, ll>>> p(n);
  ll INF = 1LL << 60;
  vector<vector<ll>> ans(n, vector<ll>(n, INF));
  for (int i = 0; i < m; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--;
    b--;
    if (c <= l) {
      p[a].emplace_back(b, c);
      p[b].emplace_back(a, c);
    }
  }
  for (int i = 0; i < n; i++) {
    priority_queue<N> q;
    q.push(N{i, 0});
    while (q.size()) {
      auto now = q.top();
      q.pop();
      if (v[i][now.now]) continue;
      v[i][now.now] = true;
      ans[i][now.now] = 1;
      for (auto &pr : p[now.now]) {
        if (v[i][pr.first]) continue;
        if (now.d + pr.second > l) continue;
        q.push(N{pr.first, now.d + pr.second});
      }
    }
    ans[i][i] = 1;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
      }
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (ans[a][b] < INF)
      cout << ans[a][b] - 1 << endl;
    else cout << "-1" << endl;
  }
  return 0;
}
