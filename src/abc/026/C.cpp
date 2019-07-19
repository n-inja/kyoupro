#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> par(n);
  vector<pair<int, int>> ps(n);
  for (int i = 0; i < n; i++) {
    ps[i] = make_pair(-1000000000, 1000000000);
  }
  for (int i = 1; i < n; i++) {
    cin >> par[i];
    par[i]--;
  }
  for (int i = n - 1; i > 0; i--) {
    int now = ps[i].first + ps[i].second + 1;
    ps[par[i]].first = max(ps[par[i]].first, now);
    ps[par[i]].second = min(ps[par[i]].second, now);
  }
  cout << ps[0].first + ps[0].second + 1 << endl;
  return 0;
}
