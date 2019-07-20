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
  vector<string> v(3);
  for (int i = 0; i < 3; i++) cin >> v[i];
  cout << v[0][0] << v[1][1] << v[2][2] << endl;
  return 0;
}
