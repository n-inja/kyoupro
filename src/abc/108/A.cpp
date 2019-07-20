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
  int k;
  cin >> k;
  int even = k / 2;
  int odd = (k + 1) / 2;
  cout << even * odd << endl;
  return 0;
}
