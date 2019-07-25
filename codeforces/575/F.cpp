#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

struct N {
  int a, b;
  ll c;
};

bool operator<(const N &l, const N &r) {
  return l.c > r.c;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  priority_queue<N> q;
  for (int i = 0; i < m; i++) {
    int a, b;
    ll w;
    cin >> a >> b >> w;
    a--;
    b--;
    q.push(N{a, b, w});
  }

  ll ans = 0;
  vector<map<int, ll>> mp(n);
  while (k && q.size()) {
    N now = q.top();
    q.pop();
    if (mp[now.a].find(now.b) != mp[now.a].end()) {
      continue;
    }
    for (auto &v : mp[now.a]) {
      q.push(N{now.b, v.first, v.second + now.c});
    }
    for (auto &v : mp[now.b]) {
      q.push(N{now.a, v.first, v.second + now.c});
    }
    mp[now.a][now.b] = now.c;
    mp[now.b][now.a] = now.c;
    ans = now.c;

    k--;
  }

  cout << ans << endl;

  return 0;
}
