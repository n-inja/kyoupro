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
  long long x, y;
  cin >> x >> y;
  long long ans = 1;
  while(y >= x * 2) {
    x *= 2;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
