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
  map<string, int> mp;
  int a, b;
  cin >> a >> b;
  string s;
  for (int i = 0; i < a + b; i++) cin >> s, mp[s]++;
  double uni = 0, in = 0;
  for (auto &v : mp) {
    if (v.second == 2)
      uni += 1.;
    in += 1.;
  }
  printf("%.12lf\n", uni / in);
  return 0;
}
