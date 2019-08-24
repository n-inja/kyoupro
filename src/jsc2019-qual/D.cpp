#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int p[505][505] = {0};

struct N {
  int l, r;
  int level;
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;

  queue<N> q;
  q.push(N{0, n, 1});
  while (q.size()) {
    N now = q.front();
    q.pop();
    if (now.r - now.l <= 1) {
      continue;
    }
    int l1 = (now.r - now.l) / 2;
    int i2 = now.l + l1;
    for (int i = now.l; i < now.l + l1; i++) {
      for (int j = i2; j < now.r; j++) {
        p[i][j] = p[j][i] = now.level;
      }
    }
    q.push(N{now.l, now.l + l1, now.level + 1});
    q.push(N{now.l + l1, now.r, now.level + 1});
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (j > i + 1)
        cout << " ";
      cout << p[i][j];
    }
    cout << endl;
  }

  return 0;
}
