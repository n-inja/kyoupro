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
  int n, a, b;
  cin >> n >> a >> b;
  a--; b--;
  if(abs(a - b) % 2 == 1) {
    cout << "Borys" << endl;
  } else {
    cout << "Alice" << endl;
  }
  return 0;
}
