#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= 100; i++)
    if (i % n == 0)
      ans++;
  cout << 100 - ans << endl;
  return 0;
}
