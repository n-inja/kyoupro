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
  vector<char> cs(n);
  for (int i = 0; i < n; i++)
    cin >> cs[i];
  map<char, int> m;
  for (int i = 0; i < n; i++)
    m[cs[i]]++;
  if (m.size() == 3)
    cout << "Three" << endl;
  else
    cout << "Four" << endl;
  return 0;
}
