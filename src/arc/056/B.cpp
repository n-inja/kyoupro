#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

struct N {
  int now, d;
};

bool operator<(const N &l, const N &r) {
  return l.d < r.d;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, m, s;
  cin >> n >> m >> s;
  s--;
  vector<vector<int>> p(n);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }

  priority_queue<N> q;

  vector<int> d(n);
  vector<bool> used(n);
  q.push(N{s, s});
  while (q.size()) {
    N now = q.top();
    q.pop();
    if (used[now.now]) continue;
    used[now.now] = true;
    d[now.now] = now.d;
    for (auto &j : p[now.now]) {
      if (used[j]) continue;
      q.push(N{j, min(j, now.d)});
    }
  }

  for (int i = 0; i < n; i++) {
    if (d[i] >= i) cout << i + 1 << endl;
  }

  return 0;
}
