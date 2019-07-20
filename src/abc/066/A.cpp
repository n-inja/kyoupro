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
  vector<int> a(3);
  int sum = 0;
  for (int i = 0; i < 3; i++) cin >> a[i], sum += a[i];
  sort(a.rbegin(), a.rend());
  cout << sum - a[0] << endl;
  return 0;
}
