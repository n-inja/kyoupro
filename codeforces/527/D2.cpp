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
  // [l, r)
  int l, r;
};

bool operator<(const N &l, const N &r) { return l.r < r.r; }

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  if (n == 1) {
    cout << "YES" << endl;
    return 0;
  }
  map<long long, vector<N>> mp;
  long long end = 0;
  for (int i = 0; i < n; i++) {
    mp[a[i]].push_back(N{i, i + 1});
    end = max(end, a[i]);
  }
  set<N> s;
  s.insert(N{-2, 0});
  for (auto &it : mp) {
    bool ok = true;
    for (auto &m : it.second) {
      auto i = lower_bound(s.begin(), s.end(), N{-2, m.l});
      if (i == s.end()) {
        if (!ok) {
          cout << "NO" << endl;
          return 0;
        }
        s.insert(m);
        ok = (m.r - m.l) % 2 == 0;
      } else {
        if (i->r == m.l) {
          int l = i->l, r = m.r;
          s.erase(i);
          auto j = lower_bound(s.begin(), s.end(), N{-2, r});
          if (j != s.end() && j->l == r) {
            r = j->r;
            s.erase(j);
          }
          ok = (r - l) % 2 == 0;
          s.insert(N{l, r});
        } else {
          if (!ok) {
            cout << "NO" << endl;
            return 0;
          }
          int l = m.l, r = m.r;
          auto j = lower_bound(s.begin(), s.end(), N{-2, r});
          if (j != s.end() && j->l == r) {
            r = j->r;
            s.erase(j);
          }
          ok = (r - l) % 2 == 0;
          s.insert(N{l, r});
        }
      }
    }
    if (it.first != end && !ok) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
