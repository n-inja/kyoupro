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

long long timelimit = 4000;
int h, w, d, k;
vector<pair<int, int>> rcs;
bool used[200][200];

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

long long score() {
  long long ret = 0;
  int x = rcs[0].first, y = rcs[0].second;
  for (int i = 1; i < d; i++) {
    ret += abs(rcs[i].first - x) + abs(rcs[i].second - y);
    x = rcs[i].first;
    y = rcs[i].second;
  }
  return ret;
}

long long dist(int id1, int id2) {
  return abs(rcs[id1].first - rcs[id2].first) +
         abs(rcs[id1].second - rcs[id2].second);
}

long long weight(int id) { return dist(id, id - 1) + dist(id, id + 1); }

int main() {
  for (int i = 0; i < 200; i++)
    for (int j = 0; j < 200; j++)
      used[i][j] = false;
  cin >> h >> w >> d >> k;
  rcs.resize(d);
  for (int i = 0; i < d; i++)
    cin >> rcs[i].first >> rcs[i].second;
  for (int i = 0; i < d; i++)
    used[rcs[i].first][rcs[i].second] = true;
  int cnt = 0;
  long long rest = timelimit;

  chrono::system_clock::time_point start = chrono::system_clock::now();

  int beforeScore = score();
  int times = 0;
  vector<string> ans;
  for (; ans.size() < 2000; times++) {
    if (++cnt % 100 == 0) {
      rest = timelimit - chrono::duration_cast<chrono::milliseconds>(
                             chrono::system_clock::now() - start)
                             .count();
      if (rest < 500) {
        break;
      }
    }
    int id = 1, maxWeight = -1000000;
    for (int i = 1; i < d - 1; i++) {
      int w = weight(i) - dist(i - 1, i + 1);
      if (w > maxWeight) {
        maxWeight = w;
        id = i;
      }
    }
    int nx, ny;
    int cost = 0, changeId = id;
    for (int i = 0; i < 1000; i++) {
      int r = mt() % (d - 2) + 1;
      if (abs(r - id) < 2)
        continue;
      if ((dist(id, r + 1) + dist(id, r - 1) +
           (dist(r, id + 1) + dist(r, id - 1)) - (weight(id) + weight(r))) <
          cost) {
        cost = (dist(id, r + 1) + dist(id, r - 1) +
                (dist(r, id + 1) + dist(r, id - 1)) - (weight(id) + weight(r)));
        changeId = r;
      }
    }
    ny = rcs[id].first, nx = rcs[id].second;
    int sc = weight(id);
    for (int i = 0; i < 10000; i++) {
      int nnx = mt() % w, nny = mt() % h;
      if (used[nny][nnx])
        continue;
      if (sc > abs(rcs[id - 1].first - nny) + abs(rcs[id - 1].second - nnx) +
                   abs(rcs[id + 1].first - nny) +
                   abs(rcs[id + 1].second - nnx)) {
        sc = abs(rcs[id - 1].first - nny) + abs(rcs[id - 1].second - nnx) +
             abs(rcs[id + 1].first - nny) + abs(rcs[id + 1].second - nnx);
        ny = nny;
        nx = nnx;
      }
    }
    if (cost < weight(id) - sc) {
      ans.push_back(to_string(rcs[id].first) + " " + to_string(rcs[id].second) +
                    " " + to_string(rcs[changeId].first) + " " +
                    to_string(rcs[changeId].second));
      auto hoge = rcs[changeId];
      rcs[changeId] = rcs[id];
      rcs[id] = hoge;
      continue;
    }

    ans.push_back(to_string(rcs[id].first) + " " + to_string(rcs[id].second) +
                  " " + to_string(ny) + " " + to_string(nx));
    used[rcs[id].first][rcs[id].second] = false;
    used[ny][nx] = true;
    rcs[id].first = ny;
    rcs[id].second = nx;
  }
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << endl;
  // cerr << "iteration: " << ans.size() << endl;
  // cerr << "beforeScore: " << beforeScore << endl;
  // cerr << "score: " << score() << endl;
  return 0;
}
