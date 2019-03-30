#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

double dp[202020] = {0};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, d, x;
  cin >> n >> d >> x;
  ll t = 0;
  for (int i = 0; i < 2 * n; i++) {
    t += d;
    d += x;
  }
  for (int i = 1; i <= n; i++)
    dp[i] = 1. / 2 / i + (i - 1.) / i * (1 + 1. / i) * dp[i - 1];
  printf("%.12lf\n", dp[n] * t);
  return 0;
}
