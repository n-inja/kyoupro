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
  int a, b, c, s;
  cin >> a >> b >> c >> s;
  if (a + b + c <= s && a + b + c + 3 >= s)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
