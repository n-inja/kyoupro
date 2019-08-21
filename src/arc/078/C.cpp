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

  auto ask = [](string n) {
    cout << "? " << n << endl;
    string a;
    cin >> a;
    return a == "Y";
  };

  bool is10pow = true;
  int k = 0;
  string base = "1";
  for (int i = 1; i < 11; i++) {
    if (!ask(base)) {
      k = i - 1;
      is10pow = false;
      break;
    }
    base.push_back('0');
  }
  if (is10pow) {
    base = "9999999999";
    for (int i = 10; i > 0; i--) {
      if (!ask(base)) {
        k = i + 1;
        cout << "! 1";
        for (int j = 0; j < i; j++) cout << "0";
        cout << endl;
        return 0;
      }
      base.pop_back();
    }
    cout << "! 1" << endl;
    return 0;
  }
  base = "999999999999";

  auto bin = [&](int i) {
    int l = 0, r = 9;
    if (i == 0) l = 1;
    base[i] = '0' + l;
    if (ask(base)) {
      return;
    }
    while (r - l > 1) {
      int m = (r + l) / 2;
      base[i] = '0' + m;
      if (ask(base)) {
        r = m;
      } else {
        l = m;
      }
    }
    base[i] = '0' + r;
  };
  for (int i = 0; i < 10; i++) {
    bin(i);
  }

  cout << "! " << base.substr(0, k) << endl;

  return 0;
}
