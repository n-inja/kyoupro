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
  int n, k;
  cin >> n >> k;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a >= k) sum++;
  }
  cout << sum << endl;
  return 0;
}
