#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
int n, m, p;
vi s;
int hx[4] = {0, 0, 1, -1};
int hy[4] = {1, -1, 0, 0};
vvi col;

struct N {
  int i, j, c;
};
bool operator<(const N &l, const N &r) { return l.c < r.c; }
vector<N> q;
struct N2 {
  int i, j, c, d;
  bool f;
};
bool operator<(const N2 &l, const N2 &r) { return l.d > r.d; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m >> p;
  col.resize(n);
  s.resize(p);
  for (int i = 0; i < p; i++)
    cin >> s[i];
  vi ans(p);
  for (int i = 0; i < n; i++) {
    col[i].resize(m);
    string t;
    cin >> t;
    for (int j = 0; j < m; j++) {
      if (t[j] == '#')
        col[i][j] = -1;
      else if (t[j] >= '1' && t[j] <= '9') {
        col[i][j] = t[j] - '0';
        q.push_back(N{i, j, t[j] - '0'});
        ans[t[j] - '1']++;
      }
    }
  }
  sort(q.begin(), q.end());
  int id = 0;
  multiset<N2> q2;
  while (id < q.size()) {
    q2.insert(N2{q[id].i, q[id].j, q[id].c, s[q[id].c - 1], true});
    int nc = q[id].c;
    id++;
    while (id < q.size() && q[id].c == nc) {
      q2.insert(N2{q[id].i, q[id].j, q[id].c, s[q[id].c - 1], true});
      id++;
    }

    while (q2.size()) {
      N2 now = *q2.begin();
      q2.erase(q2.begin());
      int i = now.i, j = now.j;
      int c = now.c, d = now.d;
      if (!now.f && col[i][j] != 0)
        continue;
      col[i][j] = c;
      if (d > 0) {
        for (int k = 0; k < 4; k++) {
          int ii = i + hy[k], jj = j + hx[k];
          if (ii < 0 || ii >= n || jj < 0 || jj >= m)
            continue;
          if (col[ii][jj] == 0)
            q2.insert(N2{ii, jj, c, d - 1, false});
        }
      } else {
        q.push_back(N{i, j, c});
      }
      if (!now.f)
        ans[now.c - 1]++;
    }
  }
  cout << ans[0];
  for (int i = 1; i < p; i++)
    cout << " " << ans[i];
  cout << endl;

  return 0;
}
