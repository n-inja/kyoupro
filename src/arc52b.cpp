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

#define P 1000000007
const double MPI = 3.141592653589793;

using namespace std;

class N {
public:
  double x, h, r;
  N(double xx, double rr, double hh) {
    x = xx;
    h = hh;
    r = rr;
  }
  double query(double a, double b) {
  //  cout << " " << mass(b) << " " << mass(a) << endl;
    return mass(b) - mass(a);
  }
  double mass(double y) {
    if(y >= x + h) {
      return r * r * MPI / 3.0 * h;
    }
    if(y <= x) {
      return 0.0;
    }
//    cout << "b" << r * r * MPI / 3.0 * h << " " << r * (h - (y - x)) / h * r * (h - (y - x)) / h * (h - (y - x)) * MPI / 3.0 << endl;
    return r * r * MPI / 3.0 * h - r * (h - (y - x)) / h * r * (h - (y - x)) / h * (h - (y - x)) * MPI / 3.0;
  }
};

int main() {
	int n, q;
  cin >> n >> q;
  vector<N> c;
  for(int i = 0; i < n; i++) {
    double x, r, h;
    cin >> x >> r >> h;
    c.push_back(N(x, r, h));
  }
  for(int i = 0; i < q; i++) {
    double ans = 0;
    double a, b;
    cin >> a >> b;
    for(int j = 0; j < n; j++) {
      ans += c[j].query(a, b);
    }
    printf("%.5lf\n", ans);
  }
	return 0;
}
