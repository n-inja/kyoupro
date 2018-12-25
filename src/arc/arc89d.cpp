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

char f(char c) {
  if(c == 'B') return 'W';
  return 'B';
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> x(n), y(n);
  vector<char> c(n);
  for(int i = 0; i < n; i++) cin >> x[i] >> y[i] >> c[i];
  for(int i = 0; i < n; i++) {
    x[i] = (x[i] % (2 * k));
    y[i] = (y[i] % (2 * k));
  }
  for(int i = 0; i < n; i++) {
    if(x[i] >= k) {
      x[i] %= k;
      c[i] = f(c[i]);
    }
    if(y[i] >= k) {
      y[i] %= k;
      c[i] = f(c[i]);
    }
  }
  
  vector<vector<int>> wc(k + 1), bc(k + 1), wn(k + 1), bn(k + 1);
  for(int i = 0; i < k + 1; i++) {
    wc[i].resize(k + 1);
    bc[i].resize(k + 1);
    wn[i].resize(k + 1);
    bn[i].resize(k + 1);
  }
  for(int i = 0; i < n; i++) {
    if(c[i]  == 'B') {
      bc[y[i] + 1][x[i] + 1]++;
    } else {
      wc[y[i] + 1][x[i] + 1]++;
    }
  }
  for(int i = 1; i < k + 1; i++) {
    for(int j = 1; j < k + 1; j++) {
      wn[i][j] = wn[i][j - 1];
      wn[i][j] += wc[i][j] + wn[i - 1][j] - wn[i - 1][j - 1];
      bn[i][j] = bn[i][j - 1];
      bn[i][j] += bc[i][j] + bn[i - 1][j] - bn[i - 1][j - 1];
    }
  }
  int bcnt = 0;
  for(int i = 0; i < n; i++) if(c[i] == 'B') bcnt++;
  int ans = 0;
  for(int i = 0; i < k; i++) {
    for(int j = 0; j < k; j++) {
      int ww = wn[k][k] - wn[k][j] - wn[i][k] + wn[i][j] * 2;
      int bb = bcnt - (bn[k][k] - bn[k][j] - bn[i][k] + bn[i][j] * 2);
      ans = max(ans, ww + bb);
      ans = max(ans, n - ww - bb);
    }
  }
  cout << ans << endl;
  return 0;
}
