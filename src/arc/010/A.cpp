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
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  for (int i = 0; i < m; i++) {
    if (n <= a) n += b;
    int c;
    cin >> c;

    n -= c;
    if (n < 0) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << "complete" << endl;
  return 0;
}
