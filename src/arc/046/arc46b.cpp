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
  long long n, a, b;
  cin >> n >> a >> b;
  if(a == b) {
    if(n % (a + 1) == 0 ) {
      cout << "Aoki" << endl;
    } else {
      cout << "Takahashi" << endl;
    }
  } else {
    if(a > b || n <= a) {
      cout << "Takahashi" << endl;
    } else {
      cout << "Aoki" << endl;
    }
  }

  return 0;
}
