#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  cout << a[0] * a[1] / 2 << endl;
  return 0;
}
