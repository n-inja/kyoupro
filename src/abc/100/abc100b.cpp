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
  int d, n;
  cin >> d >> n;
  if (n == 100)
    n++;
  for (int i = 0; i < d; i++)
    n *= 100;
  cout << n << endl;
  return 0;
}
