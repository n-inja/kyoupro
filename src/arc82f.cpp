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

struct Q {
  bool rev;
  long long t, a;
};

bool operator<(const Q &lhs, const Q &rhs) {
  if (lhs.t == rhs.t)
    return lhs.rev < rhs.rev;
  return lhs.t < rhs.t;
}

int main() {
  long long x, k;
  cin >> x >> k;
  vector<Q> query;
  for (int i = 0; i < k; i++) {
    Q q;
    q.rev = true;
    cin >> q.t;
    query.push_back(q);
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    Q q;
    q.rev = false;
    cin >> q.t >> q.a;
    query.push_back(q);
  }
  sort(query.begin(), query.end());

  long long x1 = 0, x2 = x, t = 0, y = 0;
  bool up = true, flat = false;
  long long height = 0;
  for (int i = 0; i < query.size(); i++) {
    long long delta = query[i].t - t;
    if (query[i].rev) {
      if (up) {
        y -= delta;
        x1 = max(x1, -y);
      } else {
        y += delta;
        x2 = min(x2, x - y);
      }
      if (flat) {
        if (up) {
          height -= delta;
        } else {
          height += delta;
        }
        height = min(x, height);
        height = max(0ll, height);
      } else {
        if (x2 < x1) {
          flat = true;
          if (up) {
            height = 0;
          } else {
            height = x;
          }
        }
      }
      up = !up;
      t = query[i].t;
    } else {
      long long ans;
      if (query[i].a < x1) {
        ans = x1 + y;
      } else if (query[i].a < x2) {
        ans = query[i].a + y;
      } else {
        ans = x2 + y;
      }
      if (flat) {
        ans = height;
      }
      if (up) {
        ans -= delta;
      } else {
        ans += delta;
      }
      ans = min(x, ans);
      ans = max(0ll, ans);
      cout << ans << endl;
    }
  }

  return 0;
}
