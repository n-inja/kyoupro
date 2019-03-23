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
  vll a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<bool> used(n);
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    int next = -1, now = 0;
    for (int j = 0; j < n; j++) {
      if (used[j]) {
        now++;
        continue;
      }
      if (now == a[j] - 1) {
        next = j;
      }
    }
    if (next >= 0) {
      ans.push_back(a[next]);
      used[next] = true;
    }
  }
  if (ans.size() == n) {
    for (int i = 0; i < n; i++)
      cout << ans[i] << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
