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
 
using namespace std;

int main() {
  int n;
  cin >> n;
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    long long x, y, z;
    int m;
    cin >> x >> y >> z >> m;
    vector<long long> xs(m), ys(m), zs(m);
    for(int i = 0; i < m; i++) cin >> xs[i] >> ys[i] >> zs[i];
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    sort(zs.begin(), zs.end());
    ans ^= xs[0];
    ans ^= x - xs[m - 1] - 1;
    ans ^= ys[0];
    ans ^= y - ys[m - 1] - 1;
    ans ^= zs[0];
    ans ^= z - zs[m - 1] - 1;
  }
  if(ans == 0) cout << "LOSE" << endl;
  else cout << "WIN" << endl;
  return 0;
}