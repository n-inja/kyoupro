#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n % 2 == 1) {
    cout << ":(" << endl;
    return 0;
  }
  int r = 0, l = 0, c = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(')
      l++;
    else if (s[i] == ')')
      r++;
    else
      c++;
  }
  int lpnum = n / 2 - l;
  string t;
  bool ok = true;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(' || s[i] == ')')
      t.push_back(s[i]);
    else {
      if (lpnum > 0) {
        lpnum--;
        t.push_back('(');
      } else {
        t.push_back(')');
      }
    }
    if (t[i] == '(') {
      sum++;
    } else {
      sum--;
      if (sum < 0)
        ok = false;
      if (i < n - 1 && sum <= 0)
        ok = false;
    }
  }
  if (sum != 0)
    ok = false;
  if (!ok) {
    cout << ":(" << endl;
  } else {
    cout << t << endl;
  }
  return 0;
}
