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
  double ans = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    double a;
    cin >> a;
    ans += 1. / a;
  }
  printf("%.10f\n", 1. / ans);
  return 0;
}
