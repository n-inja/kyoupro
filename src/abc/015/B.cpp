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
  int sum = 0;
  int m = n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    if (a[i] == 0) m--;
  }
  cout << (int) ceil((double) sum / m) << endl;
  return 0;
}
