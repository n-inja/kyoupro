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
  int n, m, b;
  cin >> n >> m;
  if(m % 2 == 0) {
    b = 0;
  } else {
    b = 1;
  }
  for(int i = b; i <= n; i += 2) {
    if(m < i * 3) {
      break;
    }
    int nn = n - i, mm = (m - 3 * i) / 2;
    if(mm <= 2 * nn && nn <= mm) {
      cout << 2 * nn - mm << " " << i << " " << mm - nn << endl;
      return 0;
    }
  }
  cout << "-1 -1 -1" << endl;

  return 0;
}
