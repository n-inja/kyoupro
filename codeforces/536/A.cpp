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
  vector<string> mp(n);
  for (int i = 0; i < n; i++) {
    cin >> mp[i];
  }
  int ans = 0;
  for (int i = 1; i < n - 1; i++)
    for (int j = 1; j < n - 1; j++)
      if (mp[i][j] == 'X' && mp[i][j] == mp[i - 1][j - 1] &&
          mp[i][j] == mp[i - 1][j + 1] && mp[i][j] == mp[i + 1][j - 1] &&
          mp[i][j] == mp[i + 1][j + 1])
        ans++;
  cout << ans << endl;
  return 0;
}
