#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

bool f1(double x, double y) {
  if (x >= 35.) return true;
  return false;
}

bool f2(double x, double y) {
  if (x >= 30. && x < 35.) return true;
  return false;
}

bool f3(double x, double y) {
  if (x >= 25. && x < 30.) return true;
  return false;
}

bool f4(double x, double y) {
  if (y >= 25.) return true;
  return false;
}

bool f5(double x, double y) {
  if (x >= 0. && y < 0.) return true;
  return false;
}

bool f6(double x, double y) {
  if (x < 0.) return true;
  return false;
}

function<bool(double, double)> fmp[6] = {
    f1, f2, f3, f4, f5, f6,
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  ll ans[6] = {0};
  for (int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    for (int j = 0; j < 6; j++) if (fmp[j](x, y)) ans[j]++;
  }
  printf("%d %d %d %d %d %d\n", ans[0], ans[1], ans[2], ans[3], ans[4], ans[5]);

  return 0;
}
