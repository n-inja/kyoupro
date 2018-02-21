#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <random>
#include <set>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<pair<pair<int, int>, int>> ans;
int ansMax = 850;

int add(int j, int i, int x, int y, int h) {
  return max(0, h - abs(j - x) - abs(i - y));
}

vector<pair<int, int>> vals(10000);

struct Node {
  int a;
  int x, y, i;
};

bool operator<(const Node &lhs, const Node &rhs) {
  if (vals[lhs.i].first < ans.size()) {
    for (int i = vals[lhs.i].first; i < ans.size(); i++)
      vals[lhs.i].second -= add(lhs.x, lhs.y, ans[i].first.first,
                                ans[i].first.second, ans[i].second);
    vals[lhs.i].first = ans.size();
  }
  if (vals[rhs.i].first < ans.size()) {
    for (int i = vals[rhs.i].first; i < ans.size(); i++)
      vals[rhs.i].second -= add(rhs.x, rhs.y, ans[i].first.first,
                                ans[i].first.second, ans[i].second);
    vals[rhs.i].first = ans.size();
  }
  return vals[lhs.i].second > vals[rhs.i].second;
}

vector<Node> nodes;

void check() {
  for (int i = 0; i < nodes.size(); i++) {
    if (vals[nodes[i].i].first < ans.size()) {
      for (int j = vals[nodes[i].i].first; j < ans.size(); j++)
        vals[nodes[i].i].second -=
            add(nodes[i].x, nodes[i].y, ans[i].first.first, ans[i].first.second,
                ans[i].second);
    }
  }
}

int get(int x, int y) {
  int ret = 0;
  for (int i = 0; i < ans.size(); i++)
    ret += add(x, y, ans[i].first.first, ans[i].first.second, ans[i].second);
  return ret;
}

pair<pair<int, int>, int> make_triple(int x, int y, int h) {
  return make_pair(make_pair(x, y), h);
}

int n = 100;

int toHash(int x, int y) { return y * n + x; }

int f(int x, int y, int h) {
  int ret = 0;
  for (int i = -h + 1; i < h; i++) {
    for (int j = -h + 1; j < h; j++) {
      int nx = x + j, ny = y + i;
      if (nx < 0 || nx >= n || ny < 0 || ny >= n)
        continue;
      if (abs(nx - x) + abs(ny - y) > h)
        continue;
      int now = vals[toHash(nx, ny)].second;
      int diff = h - abs(nx - x) - abs(ny - y);
      if (now == 0 && diff != 0) {
        ret -= 1000 - ansMax;
      }
      if (now == diff)
        ret += 1000 - ansMax + diff;
      else if (now > diff)
        ret += diff;
      else {
        // now = 1, diff = 5, ret = -3
        int next = now - diff;
        ret -= abs(next - now);
      }
    }
  }
  return ret;
}

vector<vector<int>> a(n), b(n);

int hx[4] = {0, 0, 1, -1};
int hy[4] = {1, -1, 0, 0};

int main() {
  for (int i = 0; i < n; i++) {
    a[i].resize(n);
    b[i].resize(n);
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      nodes.push_back(Node{a[i][j], j, i, i * n + j});
      vals[i * n + j].first = 0;
      vals[i * n + j].second = a[i][j];
    }

  int ansCnt[6] = {0};
  for (int i = 0; i < 1000; i++) {
    // check();
    sort(nodes.begin(), nodes.end());
    if (vals[nodes[0].i].second <= 0)
      break;
    if (vals[nodes[0].i].second > n * 2) {
      if (vals[nodes[0].i].second > n * 7) {
        ans.push_back(make_triple(nodes[0].x, nodes[0].y, n));
        ansCnt[0]++;
      } else if (vals[nodes[0].i].second > n * 5) {
        ans.push_back(make_triple(nodes[0].x, nodes[0].y, n / 7 * 4));
        ansCnt[1]++;
      } else if (vals[nodes[0].i].second > n * 2) {
        ans.push_back(make_triple(nodes[0].x, nodes[0].y, n / 3));
        ansCnt[2]++;
      } else if (vals[nodes[0].i].second > n) {
        ans.push_back(make_triple(nodes[0].x, nodes[0].y, n / 5));
        ansCnt[3]++;
      } else if (vals[nodes[0].i].second > 0) {
        ans.push_back(
            make_triple(nodes[0].x, nodes[0].y, vals[nodes[0].i].second / 3));
        ansCnt[4]++;
      }
    } else {
      if (ans.size() > ansMax)
        continue;
      ansCnt[5]++;
      int x, y;
      x = nodes[0].i % n;
      y = nodes[0].i / n;
      int maxScore = 0, id = 1;
      for (int j = 1; j <= n; j++) {
        int score = f(x, y, j);
        if (maxScore < score) {
          maxScore = score;
          id = j;
        }
      }
      ans.push_back(make_triple(x, y, id));
      int ex = vals[nodes[0].i].second;
      for (int j = 0; j < 4; j++) {
        int nx = x + hx[j];
        int ny = y + hy[j];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
          continue;
        if (vals[toHash(nx, ny)].second == vals[nodes[0].i].second)
          ex--;
      }
      if (ex < 1)
        ex = 1;
      ans.push_back(make_triple(x, y, (ex + 3) / 4));
    }
  }
  random_device rnd;
  for (; ans.size() < 700;) {
    int x = rnd() % 100, y = rnd() % 100;
    if (vals[toHash(x, y)].second <= 0)
      continue;
    int m = vals[toHash(x, y)].second;
    m = min(m, n);
    int imos[m + 1];
    // cerr << x << " " << y << endl;
    // cerr << vals[toHash(x, y)].second << endl;
    for (int i = 0; i < m + 1; i++)
      imos[i] = 0;
    for (int i = -m; i <= m; i++) {
      for (int j = -m; j <= m; j++) {
        int nx = x + j, ny = y + i;
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
          continue;
        if (i == 0 && j == 0)
          continue;
        if (abs(nx - x) + abs(ny - y) > m)
          continue;
        if (vals[toHash(nx, ny)].second < 0) {
          imos[abs(nx - x) + abs(ny - y)] -= 10;
          continue;
        }
        imos[abs(nx - x) + abs(ny - y)]++;
        imos[min(m, vals[toHash(nx, ny)].second) + abs(nx - x) + abs(ny - y)]--;
      }
    }
    int id = 0, sum = 0, maxNum = 0;
    for (int i = 0; i < m + 1; i++) {
      sum += imos[i];
      if (maxNum < sum) {
        maxNum = sum;
        id = i;
      }
    }
    if (id == 0)
      continue;
    ans.push_back(make_triple(x, y, id));
    // cerr << x << " " << y << " " << id << endl;
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first.first << " " << ans[i].first.second << " "
         << ans[i].second << endl;
  }
  int minusCnt = 0, justCnt = 0;
  for (int i = 0; i < n * n; i++) {
    if (vals[nodes[i].i].second < 0)
      minusCnt++;
    if (vals[nodes[i].i].second == 0)
      justCnt++;
  }
  cerr << minusCnt << " " << justCnt << endl;
  for (int i = 0; i < 6; i++)
    cerr << ansCnt[i] << endl;
  long long score = 200000000;
  for (int i = 0; i < n * n; i++) {
    score -= abs(vals[i].second);
    if (vals[i].second == 0)
      score += 1000 - ans.size();
  }
  cerr << score << endl;
  return 0;
}
