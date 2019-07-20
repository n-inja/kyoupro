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
  vector<pair<string, int>> ps(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> ps[i].first >> ps[i].second;
    sum += ps[i].second;
  }
  string ans = "atcoder";
  sum /= 2;
  for (int i = 0; i < n; i++) {
    if (ps[i].second > sum) {
      ans = ps[i].first;
    }
  }
  cout << ans << endl;
  return 0;
}
