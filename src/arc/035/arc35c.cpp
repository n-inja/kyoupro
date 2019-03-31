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
  int n, m;
  cin >> n >> m;
  long long path[500][500];
  for (int i = 0; i < 500; i++)
    for (int j = 0; j < 500; j++)
      path[i][j] = 1000000000;
  for (int i = 0; i < 500; i++)
    path[i][i] = 0;
  for (int i = 0; i < m; i++) {
    int a, b;
    long long c;
    cin >> a >> b >> c;
    a--;
    b--;
    path[a][b] = path[b][a] = min(path[a][b], c);
  }
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
  int k;
  cin >> k;
  for (int q = 0; q < k; q++) {
    int a, b;
    long long c;
    cin >> a >> b >> c;
    if (a > b)
      swap(a, b);
    a--;
    b--;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        path[i][j] = min(path[i][j], min(path[i][a] + c + path[b][j],
                                         path[i][b] + c + path[a][j]));
    long long sum = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        sum += path[i][j];
    cout << sum / 2 << endl;
  }
  return 0;
}
