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
  getline(cin, s);
  for (int i = 0; i < s.size();) {
    if (i > 0) cout << " ";
    if (s[i] == 'L') {
      cout << "<";
      i += 5;
    } else if (s[i] == 'R') {
      cout << ">";
      i += 6;
    } else if (s[i] == 'A') {
      cout << "A";
      i += 8;
    }

  }
  cout << endl;
  return 0;
}
