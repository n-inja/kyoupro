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
  vector<int> c(101 + 2);
  cin >> c[0] >> c[1];
  int k;

  cin >> k;
  for (int i = 0; i < k; i++) cin >> c[i + 2];
  vector<int> d(n + 1);
  for (int i = 0; i < k + 2; i++) d[c[i]]++;
  for (int i = 0; i < n + 1; i++)
    if (d[i] > 1) {
      cout << "NO" << endl;
      return 0;
    }
  cout << "YES" << endl;
  return 0;
}
