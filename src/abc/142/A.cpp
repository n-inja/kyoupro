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
  int a;
  cin >> a;
  int b = (a + 1) / 2;
  printf("%.12lf\n", (double) b / a);
  return 0;
}
