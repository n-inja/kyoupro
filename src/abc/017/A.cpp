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
  int sum = 0;
  for (int i = 0; i < 3; i++) {
    int a, b;
    cin >> a >> b;
    sum += a / 10 * b;
  }
  cout << sum << endl;
  return 0;
}
