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

struct N {
  int n, d;
};

bool operator<(const N &l, const N &r) { return l.d < r.d; }

int main() {
  int k;
  cin >> k;
  multiset<N> q;
  q.insert(N{1, 1});
  bool used[102020] = {0};
  while (q.size() > 0) {
    N now = *q.begin();
    q.erase(q.begin());
    if (now.n == 0) {
      cout << now.d << endl;
      return 0;
    }
    if (used[now.n])
      continue;
    used[now.n] = true;
    if (!used[(now.n + 1) % k])
      q.insert(N{(now.n + 1) % k, now.d + 1});
    if (!used[(now.n * 10) % k])
      q.insert(N{(now.n * 10) % k, now.d});
  }

  return 0;
}
