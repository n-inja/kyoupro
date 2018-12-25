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

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> b(n + 1);
  for(int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    b[l]++;
    b[r]--;
  }
  int sum = 0;
  for(int i = 0; i < n; i++) {
    sum += b[i];
    cout << sum % 2;
  }
  cout << endl;
  return 0;
}
