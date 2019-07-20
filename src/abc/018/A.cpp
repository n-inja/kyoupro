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
  vector<pair<int, int>> ps(3);
  for (int i = 0; i < 3; i++) {
    cin >> ps[i].first;
    ps[i].second = i;
    ps[i].first = -ps[i].first;
  }
  sort(ps.begin(), ps.end());
  vector<int> r(3);
  for (int i = 0; i < 3; i++) r[ps[i].second] = i + 1;
  for (int i = 0; i < 3; i++)
    cout << r[i] << endl;
  return 0;
}
