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
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    vector<int> c(26);
    for (auto &b : s)
      c[b - 'a']++;
    bool ok = true;
    int cnt = 0;
    for (int j = 0; j < 26; j++) {
      if (c[j] > 1)
        ok = false;
      else if (c[j] == 1)
        cnt++;
    }
    int li = 1000, ri = -1;
    for (int j = 0; j < 26; j++) {
      if (c[j] > 0) {
        li = min(li, j);
        ri = max(ri, j);
      }
    }

    if (ri - li + 1 != cnt) {
      ok = false;
    }
    if (ok) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
