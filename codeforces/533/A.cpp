#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = -1, mincost = 10000000;
  for (int i = 1; i <= 100; i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      sum += max(0, abs(a[j] - i) - 1);
    }
    if (sum < mincost) {
      mincost = sum;
      ans = i;
    }
  }
  cout << ans << " " << mincost << endl;
  return 0;
}
