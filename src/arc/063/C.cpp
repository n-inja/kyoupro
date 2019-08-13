#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

struct N {
  int i, v;
};

bool operator<(const N &l, const N &r) {
  return l.v > r.v;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> p(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  int k;
  cin >> k;
  priority_queue<N> q;
  ll INF = 1LL << 30;

  vector<int> ans(n, -INF);
  for (int i = 0; i < k; i++) {
    int j, val;
    cin >> j >> val;
    j--;
    q.push(N{j, val});
  }
  while (q.size()) {
    auto now = q.top();
    q.pop();
    if (ans[now.i] > -INF) {
      if (ans[now.i] != now.v) {
        cout << "No" << endl;
        return 0;
      }
      continue;
    }
    ans[now.i] = now.v;
    for (auto &j : p[now.i]) {
      if (ans[j] > -INF) {
        if (abs(ans[j] - ans[now.i]) == 1) {
          continue;
        } else {
          cout << "No" << endl;
          return 0;
        }
      } else {
        q.push(N{j, now.v + 1});
      }
    }
  }
  cout << "Yes" << endl;
  for (int i = 0; i < n; i++) cout << ans[i] << endl;

  return 0;
}
