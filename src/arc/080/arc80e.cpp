#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<set>

#define P 1000000007

using namespace std;

Template <typename T>
class SegTree {
public:
  vector<vector<T>> val;
  auto f;
  SegTree(vector<T> data, auto lambda) {
    int j = 0;
    f = lambda;
    val.push_back(data);
    for(int s = ceil((double)data.size() / 2); s > 1; s = ceil((double)s / 2)) {
      vector<T> v;
      v.resize(s);
      for(int i = 0; i < s; i++) {
        if(i*2 + i < val[j].size()) {
          v[i] = f(val[j][i*2], val[j][i*2 + 1]);
        } else {
          v[i] = val[j][i*2];
        }
      }
      val.push_back(v);
      j++;
    }
    if(data.size() > 1) {
      vector<T> v;
      v.push_back(f(val[val.size() - 1][0]), f(val[val.size() - 1][1]));
      val.push_back(v);
    }
  }
  T operator[](int i) {
    return val[0][i];
  }
};

int main() {
  return 0;
}
