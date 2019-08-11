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
  int x, k;
  cin >> k >> x;
  vector<int> ans;
  for (int i = x - k + 1; i < x + k; i++) ans.push_back(i);
  cout << ans[0];
  for (int i = 1; i < ans.size(); i++) cout << " " << ans[i];
  cout << endl;
  return 0;
}
