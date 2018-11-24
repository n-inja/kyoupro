#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;
string s;
int n;
vector<int> vk;
vector<long long> ans;

struct N {
  int pos;
  int size[100];
};

bool operator<(const N &l, const N &r) { return l.pos > r.pos; }

void solve(int q) {
  vector<int> dis(q), mis(q);
  int ds = 0, ms = 0;
  vector<N> dq, mq;
  vector<long long> esizes(q), msums(q);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < q; j++) {
      if (ds - dis[j] > 0) {
        if (dq[dis[j]].pos == i - vk[j]) {
          dis[j]++;
          esizes[j]++;
        }
      }
      if (ms - mis[j] > 0) {
        if (mq[mis[j]].pos == i - vk[j]) {
          msums[j] -= mq[mis[j]].size[j];
          mis[j]++;
        }
      }
    }
    if (s[i] == 'D') {
      N nn;
      nn.pos = i;
      dq.push_back(nn);
      ds++;
    } else if (s[i] == 'M') {
      N nn;
      nn.pos = i;
      for (int j = 0; j < q; j++) {
        nn.size[j] = esizes[j] + ds - dis[j];
        msums[j] += esizes[j] + ds - dis[j];
      }
      mq.push_back(nn);
      ms++;
    } else if (s[i] == 'C') {
      for (int j = 0; j < q; j++) {
        ans[j] += msums[j] - esizes[j] * (ms - mis[j]);
      }
    }
  }
}

int main() {
  cin >> n;
  cin >> s;
  int q;
  cin >> q;
  ans.resize(n);
  for (int i = 0; i < q; i++) {
    int k;
    cin >> k;
    vk.push_back(k);
  }
  solve(q);
  for (int i = 0; i < q; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
