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
  while (true) {
    string s;
    cin >> s;
    if (s == "end" || s == "mistake") {
      return 0;
    }
    if (s == "start") {
      int k = 0;
      cout << "? 0 1" << endl;
      fflush(stdout);
      cin >> s;
      if (s == "x") {
        cout << "! 1" << endl;
        fflush(stdout);
        continue;
      }
      for (; k < 31; k++) {
        cout << "? " << (1LL << k) << " " << (2LL << k) << endl;
        fflush(stdout);
        cin >> s;
        if (s == "x")
          break;
      }
      ll ok = (2LL << k);
      ll l = (1LL << k), r = (2LL << k);

      while (r - l > 1) {
        ll m = (l + r) / 2;
        cout << "? " << m << " " << ok << endl;
        fflush(stdout);
        cin >> s;
        if (s == "x") {
          l = m;
        } else {
          r = m;
        }
      }
      cout << "! " << r << endl;
      fflush(stdout);
      continue;
    }
  }
  return 0;
}
