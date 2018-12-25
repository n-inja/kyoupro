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

using namespace std;


int main() {
  int n;
  cin >> n;
  vector<long long> c;
  double ans = 0.0;
  c.resize(n);
  for(int i = 0; i < n; i++) cin >> c[i];
  for(int i = 0; i < n; i++) {
    int d = 0;
    for(int j = 0; j < n; j++) {
      if(i == j) continue;
      if(c[i] % c[j] == 0) d++;
    }
    ans += (d % 2 == 0) ? (((double)d + 2)/(2*d + 2)) : (0.5);
  }

  printf("%.8lf\n", ans);
  return 0;
}
