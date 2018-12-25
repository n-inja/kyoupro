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
#define area(x, y, h, w) (a[y + h][x + w] - a[y][x + w] - a[y + h][x] + a[y][x])
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> d, a;
  vector<int> memo;
  memo.resize(n * n);
  d.resize(n);
  a.resize(n + 1);
  for(int i = 0; i < n; i++) {
    a[i].resize(n + 1);
    d[i].resize(n);
    for(int j = 0; j < n; j++) cin >> d[i][j];
  }
  a[n].resize(n + 1);
  for(int i = 0; i <= n; i++) {
    a[i][0] = 0;
    a[0][i] = 0;
  }
  for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + d[i - 1][j - 1];

  int q;
  cin >> q;
  for(int _ = 0; _ < q; _++) {
    int p;
    cin >> p;
    int ans = 0;
    for(int i = 1; i <= p; i++) {
      if(memo[i - 1] > 0) {
        ans = max(ans, memo[i - 1]);
        continue;
      }
      int b = 0;
      for(int j = 1; j <= n; j++) {
        if(i % j != 0) continue;
        int h = j, w = i / j;
        for(int y = 0; y <= n - h; y++) {
          for(int x = 0; x <= n - w; x++) {
            b = max(b, area(x, y, h, w));
          }
        }
        int ho = w;
        w = h;
        h = ho;
        for(int y = 0; y <= n - h; y++) {
          for(int x = 0; x <= n - w; x++) {
            b = max(b, area(x, y, h, w));
          }
        }
      }
      ans = max(ans, b);
      memo[i - 1] = b;
      if(i > 1) memo[i - 1] = max(memo[i - 2], memo[i - 1]);
    }
    cout << ans << endl;
  }

  return 0;
}
