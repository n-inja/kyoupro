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
  int a, b;
  cin >> a >> b;
  if (a > 8 || b > 8)
    cout << ":(" << endl;
  else
    cout << "Yay!" << endl;
  return 0;
}