#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

struct N {
  int i, j, d;
};
bool operator<(const N &l, const N &r) { return l.d > r.d; }
int hx[4] = {1, -1, 0, 0};
int hy[4] = {0, 0, 1, -1};

bool used[1010][1010] = {0};
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int h, w;
  cin >> h >> w;
  vector<string> mp(h);
  for (int i = 0; i < h; i++)
    cin >> mp[i];
  priority_queue<N> q;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (mp[i][j] == '#')
        q.push(N{i, j, 0});
    }
  }
  int size = 0;
  while (q.size()) {
    N now = q.top();
    q.pop();
    if (used[now.i][now.j])
      continue;
    used[now.i][now.j] = true;
    size++;
    if (size == h * w) {
      cout << now.d << endl;
      return 0;
    }
    for (int k = 0; k < 4; k++) {
      int i = now.i + hy[k];
      int j = now.j + hx[k];
      if (i < 0 || j < 0 || i >= h || j >= w)
        continue;
      if (used[i][j])
        continue;
      q.push(N{i, j, now.d + 1});
    }
  }

  return 0;
}
