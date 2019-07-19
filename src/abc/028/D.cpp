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
  double n, k;
  cin >> n >> k;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  printf("%.10lf\n", (1. / n) * ((k - 1) / n) * ((n - k) / n) * 6 + (1. / n) * (1. / n) * ((n - 1) / n) * 3 +
                     (1. / n) * (1. / n) * (1. / n));
  return 0;
}
