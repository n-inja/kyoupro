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

int cost(int s, int n, int begin, int last) {
  int ans = 0;
  if(s > last) {
    s = begin - (s - last);
  }
  if(s < begin) {
    ans += n * (begin - s);
    s = begin;
  }
  ans += (s - begin) * (s - begin + 1) / 2 + (last - s) * (last - s + 1) / 2;
  return ans;
}

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  int ans = 10000000;
  for(int i = -300; i <= 300; i++) {
    // [i, i + g - 1] : g
    int a = 0;
    a += cost(0, g, i, i + g - 1);
    int rl = (r - 1) / 2 - 100;
    rl = min(rl, (i - 1));
    a += cost(-100, r, rl - r + 1, rl);
    int bb = 100 - (b - 1) / 2;
    bb = max(bb, (i + g));
    a += cost(100, b, bb, bb + b - 1);
    ans = min(ans, a);
  }
  cout << ans << endl;
  return 0;
}
