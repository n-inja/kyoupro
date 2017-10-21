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
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long ans = 0;
  ans += a * 1728;
  ans += b * 144;
  ans += c * 12;
  ans += d;
  cout << ans << endl;
  return 0;
}
