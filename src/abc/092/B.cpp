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
  int n, d, x;
  cin >> n >> d >> x;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    x += (d + a - 1) / a;
  }
  cout << x << endl;
  return 0;
}
