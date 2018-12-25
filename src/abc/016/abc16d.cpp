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

#define P 1000000007

using namespace std;
typedef pair<double, double> point;

bool isCross(point a1, point a2, point b1, point b2) {
    double c = (b1.first - b2.first) * (a1.second - b1.second) + (b1.second - b2.second) * (b1.first - a1.first);
    double d = (b1.first - b2.first) * (a2.second - b1.second) + (b1.second - b2.second) * (b1.first - a2.first);
    double e = (a1.first - a2.first) * (b1.second - a1.second) + (a1.second - a2.second) * (a1.first - b1.first);
    double f = (a1.first - a2.first) * (b2.second - a1.second) + (a1.second - a2.second) * (a1.first - b2.first);
    return e * f < 0 && c * d < 0;
}

int main() {
  point a, b;
  cin >> a.first >> a.second >> b.first >> b.second;
  int n;
  cin >> n;
  vector<point> p(n);
  for(int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
  int ans = 0;
  for(int i = 0; i < n; i++) if(isCross(a, b, p[i], p[(i+1)%n])) ans++;
  cout << ans/2 + 1 << endl;
  return 0;
}
