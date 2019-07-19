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
  map<int, vector<string>> ans;
  int sum = 0;
  for (int i = 1; i < 10; i++)
    for (int j = 1; j < 10; j++) {
      sum += i * j;
      ans[i * j].push_back(to_string(i) + " x " + to_string(j));
    }
  sort(ans[sum - n].begin(), ans[sum - n].end());
  for (auto &v : ans[sum - n]) {
    cout << v << endl;
  }
  return 0;
}
