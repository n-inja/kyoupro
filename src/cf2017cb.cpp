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
  vector<int> a(n);
  for(int i = 0; i <  n; i++) cin >> a[i];
  long long ans = 1, ko = 1;
  for(int i = 0; i < n; i++) if(a[i] > 1) ans *= 3;
  else ans *= 3;
  for(int i = 0; i < n; i++) {
    if(a[i] == 1) {
      ko *= 1;
    }
    else if(a[i] % 2 == 0) {
      ko *= 2;
    }
    else {
      ko *= 1;
    }
  }
  cout << ans - ko << endl;
  return 0;
}
