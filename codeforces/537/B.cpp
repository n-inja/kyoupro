#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
ll n, k, m;
vll a;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> k >> m;
  a.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  ll sum = 0;
  for (int i = 0; i < n; i++)
    sum += a[i];
  double ans = (sum + min(k * n, m)) / (double)n;
  for (int i = 0; i < n - 1 && i < m; i++) {
    double rest = n - i - 1;
    sum -= a[i];
    ans = max(ans, ((double)sum + min(k * rest, m - i - 1.0)) / rest);
  }
  printf("%.9lf\n", ans);
  return 0;
}
