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
  int p, y, i;
};

bool operator<(const N &l, const N &r) { return l.y < r.y; }

string toS(int i) {
  string s = to_string(i);
  for (int j = 0; s.size() < 6; j++) {
    s = "0" + s;
  }
  return s;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> k(n);
  vector<string> ans(m);
  vector<N> ps(m);
  for (int i = 0; i < m; i++) {
    cin >> ps[i].p >> ps[i].y;
    ps[i].p--;
    ps[i].i = i;
  }
  sort(ps.begin(), ps.end());
  for (int i = 0; i < m; i++) {
    ans[ps[i].i] = toS(ps[i].p + 1) + toS(++k[ps[i].p]);
  }
  for (int i = 0; i < m; i++)
    cout << ans[i] << endl;
  return 0;
}
