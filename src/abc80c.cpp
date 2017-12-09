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

bool check(int bit, int k) {
  return ((bit >> k) & 1) > 0;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> f(n);
  for(int i = 0; i < n; i++) f[i].resize(10);
  for(int i = 0; i < n; i++) for(int j = 0; j < 10; j++) cin >> f[i][j];
  vector<vector<int>> p(n);
  for(int i = 0; i < n; i++) p[i].resize(11);
  for(int i = 0; i < n; i++) for(int j = 0; j < 11; j++) cin >> p[i][j];
  long long ans = -1000000000000;
  for(int i = 1; i < (1 << 10); i++) {
    long long sum = 0;
    for(int j = 0; j < n; j++) {
      long long c = 0;
      for(int k = 0; k < 10; k++) if (check(i, k) && f[j][k] == 1) c++;
      sum += p[j][c];
    }
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
