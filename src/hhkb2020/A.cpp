#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  if (s == "Y") {
    for (char c : t) cout << (char) (c + 'A' - 'a');
    cout << endl;
  } else {
    cout << t << endl;
  }
  return 0;
}
