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
vector<vector<int>> p;
double s;
int n;

int main() {
  cin >> n >> s;
  p.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int f, t;
    cin >> f >> t;
    f--;
    t--;
    p[f].push_back(t);
    p[t].push_back(f);
  }
  long long c = 0;
  for (int i = 0; i < n; i++)
    if (p[i].size() == 1)
      c++;
  printf("%.12lf\n", s / c * 2);
  return 0;
}
