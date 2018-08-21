#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Bucket {
public:
  int size;
  vector<long long> v;
  long long addSum;
  long long stageNum;
  Bucket(int n) {
    size = n;
    v.resize(n);
    addSum = 0;
    stageNum = 0;
  }
  // add a [l, r)
  void add(int l, int r, long long a) {
    if (l <= 0 && r >= size) {
      addSum += a;
    } else {
      for (int i = max(0, l); i < min(size, r); i++)
        v[i] += a;
    }
  }
  // add [l, r)
  int addStage(int l, int r, long long a) {
    if (l <= 0 && r >= size) {
      stageNum++;
      add(l, r, a);
      return size;
    } else {
      int c = 0;
      for (int i = max(0, l); i < min(size, r); i++) {
        v[i] += a + c++;
      }
      return c;
    }
  }
  long long get(int i) {
    if (stageNum > 0) {
      for (int i = 0; i < size; i++)
        v[i] += stageNum * i;
      stageNum = 0;
    }
    if (addSum > 0) {
      for (int i = 0; i < size; i++)
        v[i] += addSum;
      addSum = 0;
    }
    return v[i];
  }
};

class Buckets {
public:
  vector<Bucket> b;
  int size;
  int bsize;
  int num;
  Buckets(int n) {
    size = n;
    bsize = (n + 299) / 300;
    for (; n > 0; n -= bsize) {
      Bucket c(bsize);
      b.push_back(c);
    }
    num = b.size();
  }
  void add(int l, int r, long long a) {
    for (int i = 0; i < num; i++)
      b[i].add(l - bsize * i, r - bsize * i, a);
  }
  int addStage(int l, int r) {
    int c = 0;
    for (int i = 0; i < num; i++) {
      c += b[i].addStage(l - bsize * i, r - bsize * i, c);
    }
    return c;
  }
  long long get(int i) { return b[i / bsize].get(i - (i / bsize) * bsize); }
};

int main() {
  int n, m;
  cin >> n >> m;
  Buckets b(m);
  int base;
  long long sum = 0;
  cin >> base;
  for (int i = 0; i < n - 1; i++) {
    int a;
    cin >> a;
    if (a > base) {
      b.addStage(base, a);
      sum += a - base;
    } else {
      int c = b.addStage(base, m);
      b.addStage(0, a);
      b.add(0, a, c);
      sum += m - base;
      sum += a;
    }
    base = a;
  }
  long long ma = 0;
  for (int i = 0; i < m; i++) {
    ma = max(ma, b.get(i));
  }
  cout << sum - ma << endl;
  return 0;
}
