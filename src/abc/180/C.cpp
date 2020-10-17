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
  long long n;
  cin >> n;
  set<long long> ans;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ans.insert(i);
      ans.insert(n / i);
    }
  }
  for (auto &c : ans) cout << c << endl;
  return 0;
}
