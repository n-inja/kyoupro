#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
int n, m;
vector<vector<int>> p;

struct N {
  int i, r, d;
};

bool operator<(const N &l, const N &r) {
  return l.d > r.d;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  p.resize(n);
  for (int i = 0; i < m; i++) {
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    p[s].push_back(t);
  }
  int s, t;
  cin >> s >> t;
  s--;
  t--;
  priority_queue<N> q;
  q.push(N{s, 0, 0});
  vector<vector<bool>> used(3, vector<bool>(n));
  while (q.size()) {
    N now = q.top();
    q.pop();
    if (used[now.r][now.i]) continue;
    used[now.r][now.i] = true;
    if (now.r == 0 && now.i == t) {
      cout << now.d / 3 << endl;
      return 0;
    }
    for (auto &j : p[now.i]) {
      if (used[(now.r + 1) % 3][j]) continue;
      q.push(N{j, (now.r + 1) % 3, now.d + 1});
    }
  }
  cout << -1 << endl;

  return 0;
}
