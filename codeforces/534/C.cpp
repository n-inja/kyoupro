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
  string s;
  cin >> s;
  int v = 0;
  int h = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      cout << 1 << " " << (v + 1) << endl;
      v = (v + 1) % 4;
    } else {
      cout << 3 << " " << (h * 2 + 1) << endl;
      h = (h + 1) % 2;
    }
  }
  return 0;
}
