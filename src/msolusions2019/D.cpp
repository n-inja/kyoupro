#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
int n;
vector<vector<int>> p;
vector<ll> c, d;
int id = 0;
ll score = 0;
struct N {
  int i, from;
  int d;
};

bool operator<(const N &l, const N &r) {
  return l.d < r.d;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n;
  c.resize(n);
  p.resize(n);
  d.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  for (int i = 0; i < n; i++) cin >> c[i];
  sort(c.begin(), c.end());
  reverse(c.begin(), c.end());
  int root = 0;
  for (int i = 1; i < n; i++) {
    if (p[i].size() > p[root].size()) {
      root = i;
    }
  }
  multiset<N> q;
  q.insert(N{root, -1, 0});
  while (q.size() > 0) {
    auto now = *q.begin();
    q.erase(q.begin());
    if (now.i != root)
      score += c[id];
    d[now.i] = c[id++];

    for (auto &j : p[now.i]) {
      if (now.from == j) continue;
      q.insert(N{j, now.i, now.d + 1});
    }
  }
  cout << score << endl;
  cout << d[0];
  for (int i = 1; i < n; i++) cout << " " << d[i];
  cout << endl;
  return 0;
}
