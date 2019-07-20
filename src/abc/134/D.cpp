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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> b(n);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      b[j - 1].push_back(i - 1);
    }
  }
  vector<int> c(n), ans;
  for (int i = n - 1; i >= 0; i--) {
    if ((c[i] + a[i]) % 2 == 1) {
      ans.push_back(i + 1);
      for (auto &j : b[i]) c[j]++;
    }
  }
  cout << ans.size() << endl;
  if (ans.size()) {
    cout << ans[0];
    for (int i = 1; i < ans.size(); i++) cout << " " << ans[i];
    cout << endl;
  }
  return 0;
}
