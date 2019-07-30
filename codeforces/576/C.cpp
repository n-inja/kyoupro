#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<bool> used(n * 3);
  vector<vector<pair<int, int>>> v(n * 3);
  vector<int> mat, ind;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    v[a].emplace_back(b, i);
    v[b].emplace_back(a, i);
  }
  for (int i = 0; i < n * 3; i++) {
    if (used[i]) continue;
    used[i] = true;
    bool breaked = false;
    for (auto &pr : v[i]) {
      if (used[pr.first]) continue;
      used[pr.first] = true;
      mat.push_back(pr.second + 1);
      breaked = true;
      break;
    }
    if (!breaked)
      ind.push_back(i + 1);
  }
  if (mat.size() >= n) {
    cout << "Matching" << endl;
    cout << mat[0];
    for (int i = 1; i < n; i++) cout << " " << mat[i];
    cout << endl;
  } else {
    cout << "IndSet" << endl;
    cout << ind[0];
    for (int i = 1; i < n; i++) cout << " " << ind[i];
    cout << endl;
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
