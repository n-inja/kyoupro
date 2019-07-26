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
  n = n * (n + 1) / 2;
  if (n == 1) {
    cout << "BOWWOW" << endl;
    return 0;
  }
  for (int j = 2; j * j <= n; j++) {
    if (n % j == 0) {
      cout << "BOWWOW" << endl;
      return 0;
    }
  }
  cout << "WANWAN" << endl;
  return 0;
}
