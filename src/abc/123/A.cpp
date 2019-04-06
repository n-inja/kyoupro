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
  int a, b, c, d, e, k;
  cin >> a >> b >> c >> d >> e >> k;
  if (e - a > k)
    cout << ":(" << endl;
  else
    cout << "Yay!" << endl;
  return 0;
}
