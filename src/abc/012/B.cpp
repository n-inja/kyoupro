#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

string f(int i) {
  string s = "00";
  string t = to_string(i);
  return s.substr(0, 2 - t.size()) + t;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int s;
  cin >> s;
  int m = s / 60;
  s -= m * 60;
  int h = m / 60;
  m -= h * 60;
  cout << f(h) << ":" << f(m) << ":" << f(s) << endl;
  return 0;
}
