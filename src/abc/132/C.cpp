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
  vector<ll> d(n);
  for (int i = 0; i < n; i++) cin >> d[i];
  sort(d.begin(), d.end());
  int mid = n / 2 - 1;
  cout << d[mid + 1] - d[mid] << endl;
  return 0;
}
