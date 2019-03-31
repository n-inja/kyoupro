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

int main() {
  int n;
  cin >> n;
  vector<int> t(n), x(n), y(n);
  for(int i = 0; i < n; i++) cin >> t[i] >> x[i] >> y[i];
  int nx = 0, ny = 0, nt = 0;
  for(int i = 0; i < n; i++) {
    int d = abs(x[i] - nx) + abs(y[i] - ny);
    nx = x[i]; ny = y[i];
    if(d <= (t[i] - nt) && ((t[i] - nt) - d) % 2 == 0) {
      nt = t[i];
      continue;
    } else {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
