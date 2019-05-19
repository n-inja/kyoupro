#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

bool mon(char c1, char c2) {
  if (c1 == '0' && c2 > '0') return true;
  if (c1 == '1' && c2 <= '2') return true;
  return false;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  bool ok1;
  bool ok2;

  ok1 = mon(s[0], s[1]);
  ok2 = mon(s[2], s[3]);

  if (ok1 && ok2) {
    cout << "AMBIGUOUS" << endl;
  } else if (ok1) {
    cout << "MMYY" << endl;
  } else if (ok2) {
    cout << "YYMM" << endl;
  } else {
    cout << "NA" << endl;
  }
  return 0;
}
