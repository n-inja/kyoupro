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
  int n, x;
  cin >> n >> x;
  int m = 101010101;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    x -= a;
    m = min(m, a);
  }
  cout << n + x / m << endl;
  return 0;
}
