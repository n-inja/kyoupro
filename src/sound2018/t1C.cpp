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
  long long n;
  cin >> n;
  for(long long i = 1; i < 3501; i++) for(long long j = 1; j < 3501; j++) {
    long long ue = n * i * j;
    long long shita = 4 * i * j - i * n - j * n;
    if(shita > 0 && ue % shita == 0) {
      cout << i << " " << j << " " << ue / shita << endl;
      return 0;
    }
  }
  return 0;
}
