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
  int cnt, v;
};

bool operator<(const N &l, const N &r) { return l.cnt > r.cnt; }

int main() {
  int n, odd = 0, even = 0;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  map<int, int> om, em;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      em[v[i]]++;
      even++;
    } else {
      om[v[i]]++;
      odd++;
    }
  }
  vector<N> o, e;
  for (auto i = om.begin(); i != om.end(); i++) {
    o.push_back(N{i->second, i->first});
  }

  for (auto i = em.begin(); i != em.end(); i++) {
    e.push_back(N{i->second, i->first});
  }
  sort(o.begin(), o.end());
  sort(e.begin(), e.end());
  if (o.size() == 1 && e.size() == 1) {
    if (o[0].v == e[0].v)
      cout << n / 2 << endl;
    else
      cout << 0 << endl;
    return 0;
  }
  if (o.size() == 1) {
    if (o[0].v != e[0].v)
      cout << even - e[0].cnt << endl;
    else
      cout << even - e[1].cnt << endl;
  } else if (e.size() == 1) {
    if (e[0].v != o[0].v)
      cout << odd - o[0].cnt << endl;
    else
      cout << odd - o[1].cnt << endl;
  } else {
    if (e[0].v != o[0].v) {
      cout << n - e[0].cnt - o[0].cnt << endl;
    } else {
      cout << min(n - e[0].cnt - o[1].cnt, n - e[1].cnt - o[0].cnt) << endl;
    }
  }

  return 0;
}
