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

vector<bool> p(100001);
vector<int> sum(100001);

int main() {
  for(int i = 0; i < 100001; i++) p[i] = true;
  p[0] = false;
  p[1] = false;
  for(int i = 3; i < 100001; i++) {
    for(int j = 2; j * j <= i; j++) {
      if(i % j == 0) p[i] = false;
    }
  }
  sum[0] = 0;
  sum[1] = 0;
  sum[2] = 0;
  for(int i = 3; i < 100001; i++) {
    if(p[i] && p[(i + 1) / 2]) sum[i] = sum[i - 1] + 1;
    else sum[i] = sum[i - 1];
  }
  int q;
  cin >> q;
  for(int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    cout << sum[r] - sum[l - 1] << endl;
  }
  return 0;
}
