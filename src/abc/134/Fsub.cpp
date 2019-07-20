#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll P = 1000000007;
ll ten[101010] = {0};

ll f(string s) {
  ll ret = 0;
  reverse(s.begin(), s.end());
  for (int i = 0; i < s.size(); i++) ret = (ret + (s[i] - '0') * ten[i]) % P;
  return ret;
}

int main() {
  ten[0] = 1;
  for (int i = 1; i < 101010; i++) ten[i] = (ten[i - 1] * 10) % P;

  int n = 10775;
  cout << "{";
  for (int i = 0; i < n; i++) {
    string s, t;
    cin >> s >> t;
    if (t == "1" && i != 2) {
      cout << "}," << "{";
    }
    cout << f(t) << ",";
  }
  cout << "}" << endl;
}
