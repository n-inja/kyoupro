#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<set>
#include<utility>

using namespace std;

bool isZero(double a) {
  if(a > -0.000001 && a < 0.000001) return true;
  return false;
}

typedef struct {
  double val;
  bool b;
} Ang;

bool operator>(const Ang &lhs, const Ang &rhs) {
  return lhs.val > rhs.val;
}

bool operator<(const Ang &lhs, const Ang &rhs) {
  return lhs.val < rhs.val;
}

const double pi = 3.1415926535897932384626433832795028841971;

int main() {
  long long n;
  cin >> n;
  vector<pair<double, double>> p(n);
  for(int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
  long long obt = 0, rig = 0;
  int angsize = (n - 1) * 3;

  for(int i = 0; i < n; i++) {
    Ang angle[6000];
    int cnt = 0;
    for(int j = 0; j < n; j++) {
      if(i == j) continue;
      angle[3*cnt].val = atan2(p[i].first - p[j].first, p[i].second - p[j].second);
      angle[3*cnt].b = false;
      angle[3*cnt + 1].val = angle[3*cnt].val - pi * 2;
      angle[3*cnt + 1].b = true;
      angle[3*cnt + 2].val = angle[3*cnt].val + pi * 2;
      angle[3*cnt + 2].b = true;
      cnt++;
    }
    sort(angle, angle + angsize);
    for(int j = 0; j < angsize; j++) {
      if((angle + j)->b) continue;
      Ang hoge;
      hoge.val = (angle + j)->val - pi / 2 - 0.000001;
      auto fit = lower_bound(angle, angle + angsize, hoge);
      hoge.val = (angle + j)->val + pi / 2 - 0.000001;
      auto lit = lower_bound(angle, angle + angsize, hoge);
      int r = 0;
      if(isZero(fit->val - ((angle + j)->val - pi / 2))) {
        rig++;
        fit++;
        r = 1;
      }
      if(isZero(lit->val - ((angle + j)->val + pi / 2))) {
        rig++;
        r = 1;
      }
      lit--;
      obt += n - 2 - (lit - fit) - r;
    }
  }
  // cout << rig << " " << obt << endl;
  rig /= 2; obt /= 2;
  cout << n * (n - 1) * (n - 2) / 6 - obt - rig << " " << rig << " " << obt << endl;
  return 0;
}
