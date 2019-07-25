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
  vector<int> c(7), d(7);
  for (int i = 0; i < 7; i++) cin >> c[i];
  for (int i = 0; i < 7; i++) cin >> d[i];
  ll sum = 0;
  for (int i = 0; i < 7; i++) sum += max(c[i], d[i]);
  cout << sum << endl;
  return 0;
}
