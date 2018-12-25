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
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<int> v(n), w(m);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < m; i++)
    cin >> w[i];
  int z = x;
  for (int i = 0; i < n; i++)
    z = max(z, v[i]);
  z++;
  bool yes = true;
  if (z > y)
    yes = false;
  for (int i = 0; i < m; i++)
    if (z > w[i])
      yes = false;
  if (yes)
    cout << "No War" << endl;
  else
    cout << "War" << endl;
  return 0;
}
