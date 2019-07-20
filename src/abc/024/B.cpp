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
  int n, t;
  cin >> n >> t;
  vector<int> s(1110101);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    s[a]++;
    s[a + t]--;
  }
  int ans = 0, sum = 0;
  for (int i = 0; i < 1110101; i++) {
    sum += s[i];
    if (sum > 0) ans++;
  }
  cout << ans << endl;
  return 0;
}
