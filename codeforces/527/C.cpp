#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct N {
  string s;
  int i;
};

bool operator<(const N &l, const N &r) { return l.s.size() > r.s.size(); }

int main() {
  int n;
  cin >> n;
  int m = 2 * n - 2;
  vector<N> s(m);
  for (int i = 0; i < m; i++) {
    cin >> s[i].s;
    s[i].i = i;
  }
  sort(s.begin(), s.end());
  vector<bool> b(n);
  for (int i = 2; i < m; i++) {
    if (s[i].s == s[0].s.substr(0, s[i].s.size()))
      b[s[i].s.size()] = true;
  }
  bool ok = true;
  for (int i = 1; i <= n - 2; i++) {
    if (!b[i])
      ok = false;
  }
  vector<char> ans(m);
  if (ok && s[0].s.substr(1, n - 2) == s[1].s.substr(0, n - 2)) {
    b.clear();
    b.resize(n);
    for (int i = 0; i < m; i++) {
      if (s[i].s == s[0].s.substr(0, s[i].s.size())) {
        if (b[s[i].s.size()]) {
          ans[s[i].i] = 'S';
        } else {
          b[s[i].s.size()] = true;
          ans[s[i].i] = 'P';
        }
      } else {
        ans[s[i].i] = 'S';
      }
    }
  } else {
    b.clear();
    b.resize(n);
    for (int i = 0; i < m; i++) {
      if (s[i].s == s[1].s.substr(0, s[i].s.size())) {
        if (b[s[i].s.size()]) {
          ans[s[i].i] = 'S';
        } else {
          b[s[i].s.size()] = true;
          ans[s[i].i] = 'P';
        }
      } else {
        ans[s[i].i] = 'S';
      }
    }
  }
  for (int i = 0; i < m; i++)
    cout << ans[i];
  cout << endl;

  return 0;
}
