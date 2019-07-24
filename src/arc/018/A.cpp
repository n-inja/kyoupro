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
  double bmi, height;
  cin >> height >> bmi;
  height /= 100;
  printf("%.12lf\n", bmi * height * height);
  return 0;
}
