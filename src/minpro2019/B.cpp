#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
int n = 4;
vector<vector<int>> p(4);
bool used[4] = {0};

int dfs(int i) {
  if (used[i])
    return 0;
  used[i] = true;
  int ret = 0;
  for (auto &j : p[i])
    ret = max(ret, dfs(j));
  return ret + 1;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  for (int i = 0; i < 3; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    if (p[i].size() == 1) {
      if (dfs(i) == 4) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
      break;
    }
  }
  return 0;
}
