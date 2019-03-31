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
  double a, b, c;
  cin >> a >> b >> c;
  printf("%.9lf\n", c / a * b);
  return 0;
}
