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
  int a, b;
  cin >> a >> b;
  for (int i = 0; i < 20; i++) {
    int c = 1 + (a - 1) * i;
    if (c >= b) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
