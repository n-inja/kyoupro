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
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a != c) {
      cout << a << " " << c << endl;
    } else {
      if (a != d)
        cout << a << " " << d << endl;
      else
        cout << b << " " << d << endl;
    }
  }
  return 0;
}
