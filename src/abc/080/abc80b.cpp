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
#include<utility>

using namespace std;

long long sum(long long x) {
  long long ret = 0;
  while(x > 0) {
    ret += x % 10;
    x /= 10;
  }
  return ret;
}

int main() {
  long long n;
  cin >> n;
  if(n % sum(n) == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
