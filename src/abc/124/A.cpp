#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int a[4];
  cin >> a[0] >> a[1];
  a[2] = a[0] - 1;
  a[3] = a[1] - 1;
  sort(a, a + 4);
  cout << a[2] + a[3] << endl;
  return 0;
}
