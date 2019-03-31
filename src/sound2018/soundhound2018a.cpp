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
  if (a + b == 15)
    cout << "+" << endl;
  else if (a * b == 15)
    cout << "*" << endl;
  else
    cout << "x" << endl;
  return 0;
}
