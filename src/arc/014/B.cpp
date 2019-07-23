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
  int n;
  cin >> n;
  set<string> s;
  char last = '.';
  for (int i = 0; i < n; i++) {
    string t;
    cin >> t;
    if ((last != '.' && last != t[0]) || s.find(t) != s.end()) {
      cout << (i % 2 == 0 ? "LOSE" : "WIN") << endl;
      return 0;
    }
    s.insert(t);
    last = t.back();
  }
  cout << "DRAW" << endl;

  return 0;
}
