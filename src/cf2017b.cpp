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

using namespace std;

int main() {
  int n, m, k;
  bool b = false;
  cin >> n >> m >> k;
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= m; j++) {
      int a = i * m;
      a = a - j * i + (n - i) * j;
      if(a == k) b = true;
    }
  }
  if(b) cout << "Yes" << endl;
  else cout << "No" << endl;
	return 0;
}
