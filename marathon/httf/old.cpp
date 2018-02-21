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

int n = 100, ansMax = 900;

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

  for (int i = 0; ans.size() < 900; i++) {
    // check();
    sort(nodes.begin(), nodes.end());
    if (vals[nodes[0].i].second <= 0)
      break;
    if (vals[nodes[0].i].second > n / 3) {
      int x = nodes[0].x, y = nodes[0].y, h = 0, maxScore = 0;
      for (int j = 0; j < 5; j++) {
        if (vals[nodes[j].i].second <= 0)
          break;
        int s = 1;
        if (vals[nodes[j].i].second > n * 24)
          s = 100;
        else if (vals[nodes[j].i].second > n * 20)
          s = 80;
        else if (vals[nodes[j].i].second > n * 10)
          s = 66;
        else if (vals[nodes[j].i].second > n * 7)
          s = 50;
        else if (vals[nodes[j].i].second > n * 4)
          s = 33;
        else if (vals[nodes[j].i].second > n)
          s = 20;
        else if (vals[nodes[j].i].second > 0)
          s = vals[nodes[j].i].second / 4;
        int ms = s, score = -10000000;
        for (int k = -5; k < 5; k++) {
          if (s + k < 1 || s + k > n)
            continue;
          int cs = f(nodes[j].x, nodes[j].y, s + k);
          if (score < cs) {
            score = cs;
            ms = s + k;
          }
        }
        if (maxScore < score) {
          maxScore = score;
          x = nodes[j].x;
          y = nodes[j].y;
          h = ms;
        }
      }
      if (h > 0)
        ans.push_back(make_triple(x, y, h));
      else
        break;
    } else {
      break;
      int x, y;
      x = nodes[0].i % n;
      y = nodes[0].i / n;
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
      ans.push_back(make_triple(x, y, (ex + 1) / 2));
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first.first << " " << ans[i].first.second << " "
         << ans[i].second << endl;
  }
  long long score = 200000000;
  for (int i = 0; i < n * n; i++) {
    if (vals[i].second == 0)
      score += 1000 - ans.size();
    score -= abs(vals[i].second);
  }
  cerr << score << endl;
  int up = 0, down = 0, just = 0;
  for (int i = 0; i < n * n; i++) {
    if (vals[i].second < 0)
      down++;
    else if (vals[i].second > 0)
      up++;
    else
      just++;
  }
  cerr << ans.size() << endl;
  cerr << down << " " << up << " " << just << endl;
  return 0;
}
