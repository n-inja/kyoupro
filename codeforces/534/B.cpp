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
  string s;
  cin >> s;
  int n = s.size();
  int num = 0;
  string t;
  for (int i = 0; i < n; i++) {
    t.push_back(s[i]);
    if (t.size() > 1) {
      if (t[t.size() - 2] == t[t.size() - 1]) {
        t.pop_back();
        t.pop_back();
        num++;
      }
    }
  }
  if (num % 2 == 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
