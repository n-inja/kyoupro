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
  int x, a, b;
  cin >> x >> a >> b;
  if (abs(a - x) < abs(b - x)) {
    cout << "A" << endl;
  } else {
    cout << "B" << endl;
  }
  return 0;
}
