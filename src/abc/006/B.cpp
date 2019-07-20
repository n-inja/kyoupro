#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll P = 10007;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> v(1010101);
  v[0] = 0;
  v[1] = 0;
  v[2] = 1;
  for (int i = 3; i < n; i++) v[i] = (v[i - 1] + v[i - 2] + v[i - 3]) % P;
  cout << v[n - 1] << endl;
  return 0;
}
