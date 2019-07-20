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
  string s;
  cin >> s;
  string t;
  for (char &c : s) {
    if (c == '0' || c == '1') t.push_back(c);
    else {
      if (t.size() == 0) continue;
      t.pop_back();
    }
  }
  cout << t << endl;
  return 0;
}
