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
  int q;
  cin >> q;
  for (int _ = 0; _ < q; _++) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 2) {
      if (s[0] >= s[1]) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
        cout << 2 << endl;
        cout << s[0] << " " << s[1] << endl;
      }
    } else {
      cout << "YES" << endl;
      cout << 2 << endl;
      cout << s[0] << " " << s.substr(1, n - 1) << endl;
    }
  }
  return 0;
}
