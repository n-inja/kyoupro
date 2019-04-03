#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
int n, m;
vvi p;
vi ch;

bool dfs(int i, int b) {
  if (ch[i] != -1) {
    return ch[i] == b;
  }

  ch[i] = b;
  for (auto &j : p[i])
    if (!dfs(j, 1 - b))
      return false;
  return true;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  p.resize(n);
  ch.resize(n);
  for (int i = 0; i < n; i++)
    ch[i] = -1;
  vector<pair<int, int>> path(m);
  for (int i = 0; i < m; i++) {
    int t, f;
    cin >> t >> f;
    t--;
    f--;
    p[t].push_back(f);
    p[f].push_back(t);
    path[i] = make_pair(t, f);
  }
  if (dfs(0, 1)) {
    cout << "YES" << endl;
    for (int i = 0; i < m; i++) {
      if (ch[path[i].first])
        cout << "1";
      else
        cout << "0";
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
