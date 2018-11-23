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
  int ans = 1;
  for (int i = 0; i < n; i++)
    ans *= 4;
  cout << ans << endl;
  return 0;
}
