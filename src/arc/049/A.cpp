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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  string t;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (i == a || i == b || i == c || i == d) t.push_back('"');
    t.push_back(s[i]);
  }
  if (n == d) t.push_back('"');
  cout << t << endl;
  return 0;
}
