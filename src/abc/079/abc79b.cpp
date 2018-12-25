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
  long long n;
  cin >> n;
  long long l[100] = {0};
  l[0] = 2;
  l[1] = 1;
  for(int i = 2; i < 100; i++) l[i] = l[i - 1] + l[i - 2];
  cout << l[n] << endl;
  return 0;
}
