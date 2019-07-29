#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll gcd(ll a, ll b) {
  if (b == 0) return 0;
  return gcd(b, a % b) + 1;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  if (n == 0) {
    cout << "0 0" << endl;
    return 0;
  }

  ll fib[50] = {0};
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i <= n + 2; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  cout << fib[n + 2] << " " << fib[n + 1] << endl;

  return 0;
}
