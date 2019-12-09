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
  int a, b, c;
  cin >> a >> b >> c;
  if (a + b + c >= 22) {
    cout << "bust" << endl;
  } else {
    cout << "win" << endl;
  }
  return 0;
}
