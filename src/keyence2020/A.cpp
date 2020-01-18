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
  ll h, w, n;
  cin >> h >> w >> n;
  cout << (n + max(h, w) - 1) / max(h, w) << endl;
  return 0;
}
