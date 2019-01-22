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
  vi h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    h[i] = -h[i];
  }
  int hmax = 0;
  int ans = hmax - h[0];

  for (int i = 1; i < n; i++) {
    if (h[i] < h[i - 1]) {
      ans += h[i - 1] - h[i];
    }
  }
  cout << ans << endl;
  return 0;
}
