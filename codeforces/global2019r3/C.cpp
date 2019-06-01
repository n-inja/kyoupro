#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
int n;
vector<int> p;
vector<pair<int, int>> ans;
vector<int> inv;
int d;

void sp(int i, int j) {
  if (abs(i - j) >= d) {
    swap(p[i], p[j]);
    ans.emplace_back(i, j);
    inv[p[i]] = i;
    inv[p[j]] = j;
  } else {
    if ((abs(i - (n - 1)) >= d) && abs(j - (n - 1)) >= d) {
      sp(i, n - 1);
      sp(j, n - 1);
      sp(i, n - 1);
      return;
    }
    if (abs(i - (n - 1)) >= d) {
      sp(i, n - 1);
      sp(j, 0);
      sp(0, n - 1);
      sp(j, 0);
      sp(i, n - 1);
      return;
    }
    if (abs(j - (n - 1)) >= d) {
      sp(j, n - 1);
      sp(i, 0);
      sp(0, n - 1);
      sp(i, 0);
      sp(j, n - 1);
      return;
    }
    sp(i, 0);
    sp(j, 0);
    sp(i, 0);
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n;
  p.resize(n);
  inv.resize(n);
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 0; i < n; i++) {
    p[i]--;
    inv[p[i]] = i;
  }
  d = (n + 1) / 2;

  for (int i = 0; i < n; i++) {
    if (p[i] != i)
      sp(i, inv[i]);
  }

  cout << ans.size() << endl;
  for (auto &v : ans) {
    cout << v.first + 1 << " " << v.second + 1 << endl;
  }

  return 0;
}
