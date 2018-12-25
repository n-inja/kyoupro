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

#define P 1000000007

using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int s = max(a, c);
  int e = min(b, d);
  if(e - s > 0) cout << e - s << endl;
  else cout << 0 << endl;
  return 0;
}
