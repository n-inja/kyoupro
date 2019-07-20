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
  vector<int> v(3);
  for (int i = 0; i < 3; i++) cin >> v[i];
  sort(v.begin(), v.end());
  cout << v[1] << endl;
  return 0;
}
