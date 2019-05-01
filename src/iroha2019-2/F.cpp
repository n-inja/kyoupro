#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

bool used[11][11][11][11][11][11][2] = {0};
pair<double, double> memo[11][11][11][11][11][11][2];
pair<double, double> dfs(int ax, int ay, int bx, int by, int cx, int cy,
                         bool mode) {
  if (used[ax][ay][bx][by][cx][cy][mode])
    return memo[ax][ay][bx][by][cx][cy][mode];
  used[ax][ay][bx][by][cx][cy][mode] = used[ax][ay][cx][cy][bx][by][mode] =
      true;
  used[bx][by][ax][ay][cx][cy][mode] = used[bx][by][cx][cy][ax][ay][mode] =
      true;
  used[cx][cy][bx][by][ax][ay][mode] = used[cx][cy][ax][ay][bx][by][mode] =
      true;
  if (ax == 0 && ay == 0 && bx == 0 && by == 0 && cx == 0 && cy == 0)
    return make_pair(0., 0.);
  vector<pair<double, double>> ans;
  if (ax + ay > 0) {
    pair<double, double> a;
    if (ax > 0) {
      auto v = dfs(ax - 1, ay, bx, by, cx, cy, !mode);
      if (mode)
        v.first += 100;
      else
        v.second += 100;
      a.first += v.first * ax / (ax + ay);
      a.second += v.second * ax / (ax + ay);
    }
    if (ay > 0) {
      auto v = dfs(ax, ay - 1, bx, by, cx, cy, !mode);
      if (mode)
        v.first += 50;
      else
        v.second += 50;
      a.first += v.first * ay / (ax + ay);
      a.second += v.second * ay / (ax + ay);
    }
    ans.push_back(a);
  }

  if (bx + by > 0) {
    pair<double, double> b;
    if (bx > 0) {
      auto v = dfs(ax, ay, bx - 1, by, cx, cy, !mode);
      if (mode)
        v.first += 100;
      else
        v.second += 100;
      b.first += v.first * bx / (bx + by);
      b.second += v.second * bx / (bx + by);
    }
    if (by > 0) {
      auto v = dfs(ax, ay, bx, by - 1, cx, cy, !mode);
      if (mode)
        v.first += 50;
      else
        v.second += 50;
      b.first += v.first * by / (bx + by);
      b.second += v.second * by / (bx + by);
    }
    ans.push_back(b);
  }

  if (cx + cy > 0) {
    pair<double, double> c;
    if (cx > 0) {
      auto v = dfs(ax, ay, bx, by, cx - 1, cy, !mode);
      if (mode)
        v.first += 100;
      else
        v.second += 100;
      c.first += v.first * cx / (cx + cy);
      c.second += v.second * cx / (cx + cy);
    }
    if (cy > 0) {
      auto v = dfs(ax, ay, bx, by, cx, cy - 1, !mode);
      if (mode)
        v.first += 50;
      else
        v.second += 50;
      c.first += v.first * cy / (cx + cy);
      c.second += v.second * cy / (cx + cy);
    }
    ans.push_back(c);
  }
  if (mode)
    sort(ans.begin(), ans.end(),
         [](const pair<double, double> &l, const pair<double, double> &r) {
           return l.first > r.first;
         });
  else
    sort(ans.begin(), ans.end(),
         [](const pair<double, double> &l, const pair<double, double> &r) {
           return l.second > r.second;
         });
  memo[ax][ay][bx][by][cx][cy][mode] = memo[ax][ay][cx][cy][bx][by][mode] =
      ans[0];
  memo[bx][by][ax][ay][cx][cy][mode] = memo[bx][by][cx][cy][ax][ay][mode] =
      ans[0];
  memo[cx][cy][bx][by][ax][ay][mode] = memo[cx][cy][ax][ay][bx][by][mode] =
      ans[0];
  return ans[0];
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  printf("%.9lf\n", dfs(ax, ay, bx, by, cx, cy, true).first);
  return 0;
}
