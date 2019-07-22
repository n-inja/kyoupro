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
  double va, vb, l;
  cin >> n >> va >> vb >> l;
  for (int i = 0; i < n; i++) {
    double t = l / va;
    l = vb * t;
  }
  printf("%.12lf\n", l);
  return 0;
}
