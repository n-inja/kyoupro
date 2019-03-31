#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 0)
    cout << 1 << endl;
  else if (n == 1)
    cout << 2 << endl;
  else if (n == 2)
    cout << 1 << endl;
  else
    cout << 0 << endl;
  return 0;
}
