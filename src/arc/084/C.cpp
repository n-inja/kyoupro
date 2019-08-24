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
  int k, n;
  cin >> k >> n;
  if (k % 2 == 0) {
    cout << k / 2;
    for (int i = 1; i < n; i++) cout << " " << k;
    cout << endl;
    return 0;
  }
  vector<int> ans(n, k / 2 + 1);
  for (int i = 0; i < n / 2; i++) {
    if (ans.back() == 1) {
      ans.pop_back();
    } else {
      ans.back()--;
      while (ans.size() < n)
        ans.push_back(k);
    }
  }
  cout << ans[0];
  for (int i = 1; i < ans.size(); i++) cout << " " << ans[i];
  cout << endl;
  return 0;
}
