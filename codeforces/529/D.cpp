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
  vector<int> p(n), q(n);
  for (int i = 0; i < n; i++)
    cin >> p[i] >> q[i];

  for (int i = 0; i < n; i++) {
    p[i]--;
    q[i]--;
  }
  vector<int> ans;
  if (n == 3) {
    cout << "1 2 3" << endl;
    return 0;
  }
  int now = 0;
  ans.push_back(now);
  vector<bool> b(n);
  b[0] = true;
  for (int i = 0; i < n; i++) {
    if (q[p[now]] == q[now] || p[p[now]] == q[now]) {
      now = p[now];
    } else {
      now = q[now];
    }
    b[now] = true;
    ans.push_back(now);
  }
  cout << ans[0] + 1;
  for (int i = 1; i < n; i++)
    cout << " " << ans[i] + 1;
  cout << endl;
  return 0;
}
