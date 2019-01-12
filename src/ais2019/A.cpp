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
  int n, h, w;
  cin >> n >> h >> w;
  cout << (n - h + 1) * (n - w + 1) << endl;

  return 0;
}
