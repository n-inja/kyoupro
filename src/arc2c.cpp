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

string A[16] = {
  "AA",
  "AB",
  "AX",
  "AY",
  "BA",
  "BB",
  "BX",
  "BY",
  "XA",
  "XB",
  "XX",
  "XY",
  "YA",
  "YB",
  "YX",
  "YY",
};

int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = n;
  for(int i = 0; i < 16; i++) {
    for(int j = i + 1; j < 16; j++) {
      int cu = n;
      for(int k = 0; k < n - 1; k++) {
        if(s.substr(k, 2) == A[i] || s.substr(k, 2) == A[j]) {
          k += 1;
          cu -= 1;
        }
      }
      ans = min(ans, cu);
    }
  }
  cout << ans << endl;
  return 0;
}
