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
  ll n;
  cin >> n;
  if (n % 2) {
    cout << (n - 1) / 2 << endl;
  } else {
    cout << n / 2 - 1 << endl;
  }
  return 0;
}
