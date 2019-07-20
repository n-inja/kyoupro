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
  for (int i = 10; i >= 0; i--) {
    if (n >= (1 << i)) {
      cout << (1 << i) << endl;
      return 0;
    }
  }
  return 0;
}
