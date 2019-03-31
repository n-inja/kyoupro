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
  vector<long long> a;
  cin >> n;
  a.resize(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  int t = 0, f = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] % 4 == 0){ f++;
      continue;
    }
    if(a[i] % 2 == 0) t++;
  }
  if(n - f - t <= f) {
    cout << "Yes" << endl;
  } else {
    if(t == 0 && n - f - 1 <= f) {
      cout << "Yes" << endl;
    } else
      cout << "No" << endl;
  }
  return 0;
}
