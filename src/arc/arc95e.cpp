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

int h, w;
vector<string> mp;
vector<bool> used, usedx;
vector<int> ps;
vector<int> t;

bool f() {
  for (int i = 0; i < h / 2; i++) {
    t[i] = ps[i * 2];
    t[h - i - 1] = ps[i * 2 + 1];
  }
  if (h % 2 == 1) {
    t[h / 2] = ps[h - 1];
  }
  int inv = 0;
  usedx.clear();
  usedx.resize(w);
  for (int i = 0; i < w; i++) {
    if (usedx[i])
      continue;
    for (int j = i + 1; j < w; j++) {
      if (usedx[i] || usedx[j])
        continue;
      bool ok = true;
      for (int k = 0; k < h; k++) {
        if (mp[t[k]][i] != mp[t[h - k - 1]][j]) {
          ok = false;
        }
      }
      if (ok) {
        usedx[i] = usedx[j] = true;
        inv += 2;
      }
    }
  }
  if (w % 2 == 0 && inv == w) {
    return true;
  }
  if (w % 2 == 1 && inv == w - 1) {
    bool ok = true;
    for (int i = 0; i < w; i++) {
      if (usedx[i])
        continue;
      for (int j = 0; j < h; j++) {
        if (mp[t[j]][i] != mp[t[h - j - 1]][i])
          ok = false;
      }
    }
    return ok;
  }
  return false;
}

bool dfs(int now) {
  if (now == h || (h % 2 == 1 && now == h - 1)) {
    return f();
  }
  if (now % 2 == 0) {
    for (int i = 0; i < h; i++) {
      if (!used[i]) {
        ps[now] = i;
        used[i] = true;
        bool ret = dfs(now + 1);
        used[i] = false;
        return ret;
      }
    }
  }
  bool ret = false;
  for (int i = 0; i < h; i++) {
    if (!used[i]) {
      ps[now] = i;
      used[i] = true;
      if (dfs(now + 1))
        ret = true;
      used[i] = false;
    }
  }
  return ret;
}

int main() {
  cin >> h >> w;
  mp.resize(h);
  for (int i = 0; i < h; i++)
    cin >> mp[i];

  used.resize(h);
  ps.resize(h);
  t.resize(h);

  bool ok = false;
  if (h % 2 == 0) {
    ok = dfs(0);
  } else {
    for (int i = 0; i < h; i++) {
      used[i] = true;
      ps[h - 1] = i;
      if (dfs(0))
        ok = true;
      used[i] = false;
    }
  }
  if (ok) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
