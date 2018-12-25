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

int main() {
  unsigned long long k;
  vector<unsigned long long> v;
  v.resize(50);
  cin >> k;
  cout << 50 << endl;
  if(k <= 50) {
    for(int i = 0; i < 50 - k; i++) {
      v[i] = 0;
    }
    for(int i = 49; i >= 50 - k && i >= 0; i--) {
      v[i] = i + 1;
    }
  } else {
    k -= 50;
    for(int i = 1; i <= 50; i++) {
      v[i - 1] = i + (k / 50);
      if(i > 50 - k % 50) {
        v[i - 1] += 1;
      }
    }
  }
  cout << v[0];
  for(int i = 1; i < 50; i++) cout << " " << v[i];
  cout << endl;

  return 0;
}
