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

struct A {
  int r, b;
  double dot;
};

bool operator<(const A &lhs, const A &rhs) {
  if (lhs.dot == rhs.dot) {
    return lhs.r + lhs.b < rhs.r + rhs.b;
  } else
    return lhs.dot < rhs.dot;
}

double f(double x, double y, double x2, double y2) { return x * x2 + y * y2; }

int main() {
  int caseNum;
  cin >> caseNum;
  for (int cas = 1; cas <= caseNum; cas++) {
    int r, b, ans = 0;
    cin >> r >> b;
    for (int rr = 0; rr * (rr + 1) / 2 <= r; rr++) {
      for (int bb = 0; bb * (bb + 1) / 2 <= b; bb++) {
        if (bb == 0 && rr == 0)
          continue;
        int rsum = rr * (rr + 1) / 2;
        int rn = 0;
        if (rsum == 0)
          rn = 100000;
        else
          rn = r / rsum;
        int bsum = bb * (bb + 1) / 2;
        int bn = 0;
        if (bsum == 0)
          bn = 100000;
        else
          bn = b / bsum;
        int sa = 0;
        if (rn >= bb + 1) {
          sa = max(sa, (bb + 1) * (rr + 1) - 1);
        } else {
          int rrest = r - rr * (rr + 1) / 2;
          int rmin = 0;
          int rmax = rr;
          while (rmax - rmin > 1) {
            int rm = (rmin + rmax) / 2;
            if (rm * (rm + 1) / 2 <= rrest) {
              rmin = rm;
            } else {
              rmax = rm;
            }
          }
          sa = max(sa, (rn) * (rr + 1) + rmin - 1);
        }
        if (bn >= rr + 1) {
          sa = max(sa, (bb + 1) * (rr + 1) - 1);
        } else {
          int brest = b - bb * (bb + 1) / 2;
          int bmin = 0;
          int bmax = bb;
          while (bmax - bmin > 1) {
            int bm = (bmin + bmax) / 2;
            if (bm * (bm + 1) / 2 <= brest) {
              bmin = bm;
            } else {
              bmax = bm;
            }
          }
          sa = max(sa, (bn) * (bb + 1) + bmin - 1);
        }
        ans = max(ans, sa);
        cout << sa << " " << rr << " " << bb << endl;
      }
    }
    cout << "Case #" << cas << ": " << ans << endl;
  }
  return 0;
}
