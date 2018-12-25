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

long long n;
long long d, x, y;

double dp[1001][1001][2] = {};
int hx[4] = {1, -1, 0, 0};
int hy[4] = {0, 0, 1, -1};

int main() {
  cin >> n >> d >> x >> y;
  if(x%d == y%d && y%d == 0) {
    if(n > 30) return 0;
    dp[0][0][1] = 1.00000000000000000;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j <= n; j++) for(int k = 0; k <= j; k++) dp[j][k][0] = dp[j][k][1];
      for(int j = 0; j <= n; j++) for(int k = 0; k <= j; k++) dp[j][k][1] = 0.0000000000000000;
      for(int j = 0; j <= n; j++) for(int k = 0; k <= j; k++) {
        for(int l = 0; l < 4; l++) {
          int xx = abs(j + hx[l]), yy = abs(k + hy[l]);
          if(yy > xx) swap(xx, yy);
          dp[j][k][1] += dp[xx][yy][0] * 0.250000000000000;
        }
      }
    }
    long long xx = abs(x/d), yy = abs(y/d);
    if(yy > xx) swap(xx, yy);
    printf("%.10f\n", dp[xx][yy][1]);
  } else {
    cout << "0.0000000000000" << endl;
  }
  return 0;
}
