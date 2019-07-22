#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

string mp[256];

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  for (int i = 0; i < 256; i++) mp[i] = "";
  mp['b'] = mp['c'] = "1";
  mp['d'] = mp['w'] = "2";
  mp['t'] = mp['j'] = "3";
  mp['f'] = mp['q'] = "4";
  mp['l'] = mp['v'] = "5";
  mp['s'] = mp['x'] = "6";
  mp['p'] = mp['m'] = "7";
  mp['h'] = mp['k'] = "8";
  mp['n'] = mp['g'] = "9";
  mp['z'] = mp['r'] = "0";

  int n;
  cin >> n;
  vector<string> w(n), ans;
  for (int i = 0; i < n; i++) cin >> w[i];
  for (int i = 0; i < n; i++) {
    string t = "";
    for (char &c : w[i]) {
      if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
      t += mp[c];
    }
    if (t.size()) ans.push_back(t);
  }
  if (ans.size()) {
    cout << ans[0];
    for (int i = 1; i < ans.size(); i++) cout << " " << ans[i];
    cout << endl;
  } else {
    cout << endl;
  }

  return 0;
}
