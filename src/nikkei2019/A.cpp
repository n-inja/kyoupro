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
  int n, a, b;
  cin >> n >> a >> b;
  cout << min(a, b) << " " << max(a + b - n, 0) << endl;
  return 0;
}
