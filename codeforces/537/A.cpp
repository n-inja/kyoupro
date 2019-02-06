#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  if (s.size() != t.size()) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o')
      s[i] = 2;
    else
      s[i] = 1;
    if (t[i] == 'a' || t[i] == 'i' || t[i] == 'u' || t[i] == 'e' || t[i] == 'o')
      t[i] = 2;
    else
      t[i] = 1;
  }
  if (s == t)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
