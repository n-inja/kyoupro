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

const long long PRIME = 1000000007;

using namespace std;

int main() {
  int n;
  cin >> n;
  int c;
  cin >> c;
  cout << c;
  for(int i = 1; i < n; i++) {
    int b;
    cin >> b;
    cout << "," << b;
  }
  cout << endl;
  return 0;
}
