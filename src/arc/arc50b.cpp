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

long long r, b, x, y;

long long _max(long long lhs, long long rhs) {
  return lhs > rhs ? lhs : rhs;
}

long long _min(long long lhs, long long rhs) {
  return lhs < rhs ? lhs : rhs;
}

bool f(long long k) {
  if(r < k || b < k) {
    return false;
  }
  return ((r - k) / (x - 1) + (b - k) / (y - 1)) >= k;
}

int main() {
  cin >> r >> b >> x >> y;
  long long rangeMin = 0, rangeMax = 1000000000000000000000;
  long long piv;
  while(rangeMax - rangeMin > 1) {
    piv = (rangeMin + rangeMax) / 2;
  //  cout << piv << endl;
    if(f(piv)) {
      rangeMin = piv;
    } else {
      rangeMax = piv;
    }
  }
  cout << rangeMin << endl;
  return 0;
}
