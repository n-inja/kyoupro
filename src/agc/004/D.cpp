#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

vi a, dep;
vvi inv;
vector<bool> ok;

void dfs(int i, int d) {
  dep[i] = d;
  for (auto &j : inv[i]) dfs(j, d + 1);
}

void use(int i, int d) {
  ok[i] = true;
  if (d > 0)
    for (auto &j : inv[i]) use(j, d - 1);
}

struct N {
  int i, d;
};

bool operator<(const N &l, const N &r) {
  return l.d > r.d;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  a.resize(n);
  dep.resize(n);
  ok.resize(n);
  ll ans = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  if (a[0] != 1)
    ans++;
  for (int i = 0; i < n; i++) {
    a[i]--;
  }
  a[0] = 0;
  inv.resize(n);
  for (int i = 1; i < n; i++) {
    inv[a[i]].push_back(i);
  }
  multiset<N> q;

  dfs(0, 0);
  for (int i = 0; i < n; i++) {
    if (dep[i] <= k) ok[i] = true;
    else q.insert(N{i, dep[i]});
  }

  vvi p(n);
  for (int i = 0; i < n; i++) {
    p[i].resize(20);
    p[i][0] = a[i];
  }
  for (int j = 1; j < 20; j++) {
    for (int i = 0; i < n; i++) {
      p[i][j] = p[p[i][j - 1]][j - 1];
    }
  }
  if (k == 1) {
    for (int i = 0; i < n; i++) if (!ok[i]) ans++;
    cout << ans << endl;
    return 0;
  }

  while (q.size()) {
    N now = *q.begin();
    q.erase(q.begin());
    if (ok[now.i]) {
      continue;
    }
    int k2 = k - 1;
    int keta = 0;
    int t = now.i;
    while (k2) {
      if (k2 % 2)
        t = p[t][keta];
      k2 >>= 1;
      keta++;
    }
    use(t, k - 1);
    ans++;
  }
  cout << ans << endl;
  return 0;
}
