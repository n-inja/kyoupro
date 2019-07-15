#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
int n, m;

class U {
public:
  int n;
  vector<int> p, s;

  U(int _) {
    n = _;
    p.resize(n);
    s.resize(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
      s[i] = 1;
    }
  }

  bool connect(int a, int b) {
    int ap, bp;
    for (ap = p[a]; ap != p[ap]; ap = p[ap]);
    for (bp = p[b]; bp != p[bp]; bp = p[bp]);
    if (ap == bp)
      return true;
    int mi = min(ap, bp), ma = max(ap, bp);
    p[ma] = mi;
    s[mi] += s[ma];
    s[ma] = 0;
    for (int pp = a; pp != mi;) {
      int next = p[pp];
      p[pp] = mi;
      pp = next;
    }
    for (int pp = b; pp != mi;) {
      int next = p[pp];
      p[pp] = mi;
      pp = next;
    }
    return false;
  }

  int q(int a) {
    int ap;
    for (ap = a; ap != p[ap]; ap = p[ap]);
    return s[ap];
  }

  int parent(int a) {
    int ap;
    for (ap = a; ap != p[ap]; ap = p[ap]);
    return p[ap];
  }

  bool query(int a, int b) { return parent(a) == parent(b); }
};

vector<int> deg;
vector<vector<int>> p;
vector<pair<int, int>> ans;

void dfs(int i, int from) {
  for (auto &j : p[i]) {
    if (j == from) continue;
    dfs(j, i);
  }
  if (from < 0) return;

  if (deg[i] % 2 == 1) {
    ans.emplace_back(i, from);
    deg[i]++;
  } else {
    ans.emplace_back(from, i);
    deg[from]++;
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  p.resize(n);
  deg.resize(n);
  U uf(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (uf.connect(a, b)) {
      deg[a]++;
      ans.emplace_back(a, b);
    } else {
      p[a].push_back(b);
      p[b].push_back(a);
    }
  }
  if (m % 2 == 1) {
    cout << -1 << endl;
    return 0;
  }
  dfs(0, -1);

  for (auto &v : ans) cout << v.first + 1 << " " << v.second + 1 << endl;

  return 0;
}
