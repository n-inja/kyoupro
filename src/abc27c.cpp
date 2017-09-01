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
  long long n;
  cin >> n;
  long long xmx = n;
  long long xmn = (xmx + 2) / 2;
  if(n == 1) {
    cout << "Aoki" << endl;
    return 0;
  }
  for(int i = 0; i < 100; i++) {
    // cout << xmn << "," << xmx << endl;
    if(xmn <= 1 || xmx <= 1) {
      cout << "Aoki" << endl;
      return 0;
    }
    long long ymn, ymx;
    ymx = xmn - 1;
    ymn = xmn / 2;
    // cout << ymn << "," << ymx << endl;
    if(ymn <= 1 || ymx <= 1) {
      cout << "Takahashi" << endl;
      return 0;
    }
    xmx = ymn - 1;
    xmn = (ymn + 1) / 2;
  }
  return 0;
}
