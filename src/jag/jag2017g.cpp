#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
#include<vector>
#include<math.h>

using namespace std;

struct Pos {
  double x, y;
};

double cross(Pos v1, Pos v2) {
  return v1.x * v2.x + v1.y * v2.y;
}

double isZero(double x) {
  return x <= 0.000000000001;
}

double leng(Pos v) {
  double lengleng = cross(v, v);
  if(isZero(lengleng)) return 0.0;
  return sqrt(lengleng);
}

double dist(Pos v1, Pos v2) {
  Pos v{v1.x - v2.x, v1.y - v2.y};
  return leng(v);
}

double distLinePos(Pos p, Pos l1, Pos l2) {
  Pos vec{l2.x - l1.x, l2.y - l1.y};
  if(isZero(leng(vec))) dist(l1, p);
  p.x -= l1.x; p.y -= l1.y;
  double k = sqrt(cross(p, vec) / cross(vec, vec));
  cout << k << endl;
  if(k < 0) return leng(p);
  else if(k > 1) return dist(p, vec);
  vec.x /= k;
  vec.y /= k;
  return dist(p, vec);
}

bool isCol(Pos s, Pos t, Pos v, double r1, double r2) {
  if(distLinePos(v, s, t) <= r1 + r2) return true;
  return false;
}

int count(int bit) {
  int ret = 0;
  while(bit > 0) {
    ret += bit & 1;
    bit >>= 1;
  }
  return ret;
}

bool isB(int bit, int k) {
  return ((bit >> k) & 1) > 0;
}

int main() {
  int n;
  cin >> n;
  vector<double> r(n);
  vector<vector<Pos>> st(n);
  for(int i = 0; i < n; i++) {
    st[i].resize(2);
    cin >> r[i] >> st[i][0].x >> st[i][0].y >> st[i][1].x >> st[i][1].y;
  }
  cout << distLinePos(st[2][0], st[2][1], st[1][0]) << endl;
  return 0;
  bool bitDP[1 << n] = {0};
  bitDP[0] = true;
  int ans = 0;
  for(int i = 0; i < (1 << n); i++) {
    if(!bitDP[i]) continue;
    cout << i << endl;
    ans = max(ans, count(i));
    for(int j = 0; j < n; j++) {
      if(isB(i, j)) continue;
      bool b = false;
      for(int k = 0; k < n; k++) {
        if(j == k) continue;
        int kst = isB(i, k) ? 1 : 0;
        if(isCol(st[j][0], st[j][1], st[k][kst], r[j], r[k])) b = true;
      }
      if(b) continue;
      bitDP[i | (1 << j)] = true;
    }
  }
  cout << ans << endl;
  return 0;
}
