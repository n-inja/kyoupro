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
  long long a, b;
  cin >> a >> b;
  int k;
  cin >> k;
  set<long long> s;
  for (long long i = a; i < a + k && i <= b; i++)
    s.insert(i);
  for (long long i = b; i > b - k && i >= a; i--)
    s.insert(i);
  auto it = s.begin();
  for (; it != s.end(); it++)
    cout << *it << endl;
  return 0;
}
