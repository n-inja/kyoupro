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
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    int b;
    for (int j = 0; j < k; j++) {
      cin >> b;
      a[b - 1]++;
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++)
    if (a[i] == n)
      ans++;
  cout << ans << endl;
  return 0;
}
