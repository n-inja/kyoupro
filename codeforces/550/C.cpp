#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vll a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  vvl ans(2);
  int cnt = 0, now = -1;
  for (int i = 0; i < n; i++) {
    if (now != a[i]) {
      now = a[i];
      cnt = 0;
    }
    if (cnt > 1) {
      cout << "NO" << endl;
      return 0;
    }
    ans[cnt].push_back(a[i]);
    cnt++;
  }
  cout << "YES" << endl;
  reverse(ans[1].begin(), ans[1].end());
  for (int i = 0; i < 2; i++) {
    cout << ans[i].size() << endl;
    if (ans[i].size()) {
      cout << ans[i][0];
      for (int j = 1; j < ans[i].size(); j++)
        cout << " " << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}
