#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

long long g = 0;
long long L;

class T {
public:
  T *l, *r;
  int dep;
  T(int d, string &s) {
    l = r = nullptr;
    dep = d;
    if (d == s.size()) {
    } else {
      if (s[d] == '0') {
        l = new T(d + 1, s);
      } else {
        r = new T(d + 1, s);
      }
    }
  }
  ~T() {
    if (l != nullptr) {
      delete l;
    }
    if (r != nullptr) {
      delete r;
    }
  }
  void append(string &s) {
    if (s.size() == dep) {
      return;
    }
    if (s[dep] == '0') {
      if (l == nullptr) {
        l = new T(dep + 1, s);
      } else {
        l->append(s);
      }
    } else {
      if (r == nullptr) {
        r = new T(dep + 1, s);
      } else {
        r->append(s);
      }
    }
  }
  void solve() {
    if (l == nullptr && r == nullptr) {
      return;
    } else {
      if (l != nullptr)
        l->solve();
      if (r != nullptr)
        r->solve();
      if (l == nullptr || r == nullptr) {
        int r = 0;
        while ((((L - dep) >> r) & 1) == 0)
          r++;
        g ^= (1 << r);
      }
    }
  }
};

int main() {
  int n;
  cin >> n >> L;
  vector<string> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  T t(0, v[0]);
  for (int i = 1; i < n; i++)
    t.append(v[i]);
  t.solve();
  if (g == 0)
    cout << "Bob" << endl;
  else
    cout << "Alice" << endl;

  return 0;
}
