#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
struct N {
  int i, j, d;
  char c;
};

bool operator<(const N &l, const N &r) {
  return l.d > r.d;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int h, w;
  cin >> h >> w;
  vector<string> mp(h);
  for (int i = 0; i < h; i++) cin >> mp[i];
  priority_queue<N> q;

  if (mp[0][0] == '#') q.push(N{0, 0, 1, '#'});
  else q.push(N{0, 0, 0, '.'});
  vector<vector<bool>> used(h, vector<bool>(w, 0));
  while (q.size()) {
    auto now = q.top();
    q.pop();
    if (now.i == h - 1 && now.j == w - 1) {
      cout << (now.d + 1) / 2 << endl;
      return 0;
    }
    if (used[now.i][now.j]) continue;
    used[now.i][now.j] = true;
    if (now.i < h - 1 && !used[now.i + 1][now.j]) {
      if (now.c == mp[now.i + 1][now.j])
        q.push(N{now.i + 1, now.j, now.d, mp[now.i + 1][now.j]});
      else q.push(N{now.i + 1, now.j, now.d + 1, mp[now.i + 1][now.j]});
    }
    if (now.j < w - 1 && !used[now.i][now.j + 1]) {
      if (now.c == mp[now.i][now.j + 1])
        q.push(N{now.i, now.j + 1, now.d, mp[now.i][now.j + 1]});
      else q.push(N{now.i, now.j + 1, now.d + 1, mp[now.i][now.j + 1]});
    }
  }
  return 0;
}
