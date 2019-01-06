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
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  vector<pair<int, int>> q(m);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    b[i] = a[i];
  for (int i = 0; i < m; i++)
    cin >> q[i].first >> q[i].second;
  for (int i = 0; i < m; i++) {
    int pos = q[i].first - 1;
    q[i].first = b[pos];
    b[pos] = q[i].second;
    q[i].first--;
    q[i].second--;
  }
  vector<int> v(n), w(n);
  for (int i = 0; i < n; i++) {
    v[a[i] - 1]++;
    if (a[i] - v[a[i] - 1] >= 0)
      w[a[i] - v[a[i] - 1]]++;
  }

  int moves = 0;
  for (int i = 0; i < n; i++)
    if (w[i] == 0)
      moves++;

  for (int i = 0; i < m; i++) {
    int bef = q[i].first, aft = q[i].second;
    if (bef - v[bef] + 1 >= 0) {
      w[bef - v[bef] + 1]--;
      if (w[bef - v[bef] + 1] == 0) {
        moves++;
      }
    }
    v[bef]--;
    v[aft]++;
    if (aft - v[aft] + 1 >= 0) {
      w[aft - v[aft] + 1]++;
      if (w[aft - v[aft] + 1] == 1) {
        moves--;
      }
    }
    cout << moves << endl;
  }
  return 0;
}
