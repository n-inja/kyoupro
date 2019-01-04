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
  long long n;
  cin >> n;
  vector<int> p;
  for (int i = 0; (1LL << (i + 1)) <= n + 1; i++)
    p.push_back(i);
  long long plen = p.size();
  long long m = n - ((1LL << plen) - 1);
  set<int> used;
  for (int k = plen - 1; k >= 0; k--) {
    if ((m >> k) & 1) {
      p.insert(p.begin() + k, 99 - k);
      used.insert(99 - k);
    }
  }
  vector<int> q;
  cout << p.size() * 2 << endl;
  for (int i = 0; i < p.size(); i++) {
    q.push_back(p[i] + 1);
  }
  for (int i = 0; i < plen; i++)
    q.push_back(i + 1);
  for (auto &i : used)
    q.push_back(i + 1);
  cout << q[0];
  for (int i = 1; i < q.size(); i++)
    cout << " " << q[i];
  cout << endl;
  return 0;
}
