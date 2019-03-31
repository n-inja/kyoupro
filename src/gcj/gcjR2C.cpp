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

int main() {
  int caseNum;
  cin >> caseNum;
  for (int cas = 1; cas <= caseNum; cas++) {
    int n;
    cin >> n;
    vector<vector<int>> mp(n);
    for (int i = 0; i < n; i++) {
      mp[i].resize(n);
      for (int j = 0; j < n; j++) {
        cin >> mp[i][j];
      }
    }
    int r[101][300] = {0}, c[101][300] = {0};
    int *rp[101];
    int *cp[101];
    for (int i = 0; i < n; i++) {
      rp[i] = r[i] + 150;
      cp[i] = c[i] + 150;
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        rp[i][mp[i][j]]++;
        cp[j][mp[i][j]]++;
      }
    int ans = 0;
    for (int k = 1; k <= n; k++) {
      int sum = 0;
      int rs = 0, cs = 0;
      for (int i = 0; i < n; i++) {
        if (rp[i][k] > 0)
          rs++;
        sum += rp[i][k];
      }
      for (int i = 0; i < n; i++) {
        if (cp[i][k] > 0)
          cs++;
      }
      ans += sum - min(cs, rs);
    }
    for (int k = -1; k >= -n; k--) {
      int sum = 0;
      int rs = 0, cs = 0;
      for (int i = 0; i < n; i++) {
        if (rp[i][k] > 0)
          rs++;
        sum += rp[i][k];
      }
      for (int i = 0; i < n; i++) {
        if (cp[i][k] > 0)
          cs++;
      }
      ans += sum - min(cs, rs);
    }
    cout << "Case #" << cas << ": " << ans << endl;
  }
  return 0;
}
