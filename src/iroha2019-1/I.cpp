#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

struct N {
  int i, last, d;
};
bool operator<(const N &l, const N &r) { return l.d < r.d; }

vector<set<int>> used;
vector<vector<pair<int, int>>> p;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  p.resize(n);
  used.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    p[a].push_back(make_pair(b, c));
    p[b].push_back(make_pair(a, c));
  }
  multiset<N> q;
  q.insert(N{0, -1, 0});
  while (q.size()) {
    N now = *q.begin();
    q.erase(q.begin());
    if (used[now.i].find(now.last) != used[now.i].end()) {
      continue;
    }
    used[now.i].insert(now.last);
    if (now.i == n - 1) {
      cout << now.d * k << endl;
      return 0;
    }
    for (auto &v : p[now.i]) {
      if (used[v.first].find(v.second) != used[v.first].end())
        continue;
      q.insert(N{v.first, v.second, now.d + (v.second != now.last)});
    }
  }
  cout << -1 << endl;

  return 0;
}
