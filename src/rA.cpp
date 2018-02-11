#include <algorithm>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <random>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

mt19937 mt(1);

struct Node {
  int stages[8];
  unsigned long long data[625];
  long long scores[8];
  long long score;
};

long long timelimit = 4000;
int n, k, h, w, t, minTime = 0;
string hv = "UDLR";
int hx[4] = {0, 0, -1, 1};
int hy[4] = {-1, 1, 0, 0};
vector<vector<string>> mps(n);
vector<pair<int, int>> sts(n);

int decode(Node &node, int index) {
  int shift = (index % 16) * 4;
  return ((node.data[index / 16]) >> shift) & 0b1111;
}

// e2 < e1
bool f(double e1, double e2, double t) {
  double ex = pow(2.7, (e2 - e1) / t);
  return ex > (double)(mt() % 10000) / 10000;
}

unsigned long long getMask(int index) {
  unsigned long long ret = 0;
  ret--;
  unsigned long long a = 0b1111;
  return ret ^ (a << (index * 4));
}

void encode(Node &node, int index, int v) {
  int shift = (index % 16) * 4;
  node.data[index / 16] =
      (node.data[index / 16] & getMask(index % 16)) | (v << shift);
}

long long score(Node &node, int index, bool reset) {
  long long ret = 0;
  if (reset)
    minTime = t;
  vector<vector<bool>> bs(h);
  for (int j = 0; j < h; j++)
    bs[j].resize(w);
  int mapId = node.stages[index];
  int x = sts[mapId].second, y = sts[mapId].first;
  bs[y][x] = true;
  for (int j = 0; j < t; j++) {
    int nx = x + hx[decode(node, j)], ny = y + hy[decode(node, j)];
    if (nx < 0 || nx >= w || ny < 0 || ny >= h)
      continue;
    if (mps[mapId][ny][nx] == '#')
      continue;
    if (mps[mapId][ny][nx] == 'x') {
      minTime = min(j, minTime);
      break;
    }
    if (!bs[ny][nx])
      ret++;
    bs[ny][nx] = true;
    x = nx;
    y = ny;
  }
  return ret;
}

int main() {
  cin >> n >> k >> h >> w >> t;
  mps.resize(n);
  sts.resize(n);
  for (int i = 0; i < n; i++) {
    mps[i].resize(h);
    for (int j = 0; j < h; j++)
      cin >> mps[i][j];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < h; j++)
      for (int k = 0; k < w; k++)
        if (mps[i][j][k] == '@') {
          mps[i][j][k] = '.';
          sts[i] = make_pair(j, k);
        }
  }
  int cnt = 0;
  long long rest = timelimit;
  Node ans, now;
  for (int i = 0; i < k; i++)
    now.stages[i] = i;
  for (int i = 0; i < t; i++)
    encode(now, i, mt() % 4);
  now.score = 0;
  for (int i = 0; i < k; i++) {
    now.scores[i] = score(now, i, i == 0);
    now.score += now.scores[i];
  }
  ans = now;
  chrono::system_clock::time_point start = chrono::system_clock::now();

  while (true) {
    if (++cnt % 100 == 0) {
      rest = timelimit - chrono::duration_cast<chrono::milliseconds>(
                             chrono::system_clock::now() - start)
                             .count();
      if (rest < 500) {
        break;
      }
    }
    Node next = now;
    if (cnt % 10 == 0) {
      vector<bool> used(n);
      for (int i = 0; i < k; i++)
        used[next.stages[i]] = true;
      int changeIndex = 0;
      for (int i = 0; i < k; i++)
        if (now.scores[changeIndex] > now.scores[i])
          changeIndex = i;
      int changeTo = mt() % n;
      while (used[changeTo])
        changeTo = mt() % n;
      next.stages[changeIndex] = changeTo;
      next.score -= now.scores[changeIndex];
      int nowMinTime = minTime;
      next.scores[changeIndex] = score(next, changeIndex, true);
      minTime = min(nowMinTime, minTime);
      next.score += next.scores[changeIndex];
    } else {
      int nowDir = decode(now, minTime);
      int nextDir = mt() % 4;
      if (nextDir == nowDir)
        nextDir = (nextDir + 1) % 4;
      encode(next, minTime, nextDir);
      next.score = 0;
      for (int i = 0; i < k; i++) {
        next.scores[i] = score(next, i, i == 0);
        next.score += next.scores[i];
      }
    }
    if (next.score > ans.score) {
      ans = next;
    }
    // sennikansuu
    if (now.score > next.score) {
      if (f(now.score, next.score, rest)) {
        now = next;
      }
    } else {
      now = next;
    }
  }
  cout << ans.stages[0];
  for (int i = 1; i < k; i++)
    cout << " " << ans.stages[i];
  cout << endl;
  for (int i = 0; i < t; i++)
    cout << hv[decode(ans, i)];
  cout << endl;
  // cerr << "iteration: " << cnt << endl;
  // cerr << "score: " << ans.score << endl;
  return 0;
}
