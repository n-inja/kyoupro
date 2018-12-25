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
  int a, b, n;
  cin >> n >> a >> b;
  cout << min(b, a * n) << endl;
  return 0;
}
