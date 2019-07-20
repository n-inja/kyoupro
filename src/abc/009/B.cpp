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
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.rbegin(), v.rend());
  for (int i = 0; i < n; i++) {
    if (v[0] != v[i]) {
      cout << v[i] << endl;
      break;
    }
  }

  return 0;
}
