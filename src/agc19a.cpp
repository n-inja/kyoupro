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
  long long q, h, s, d, n;
  cin >> q >> h >> s >> d >> n;
  long long l1 = min(min(q * 4, h * 2), s);
  long long l2 = min(l1 * 2, d);
  cout << (n / 2) * l2 + (n % 2) * l1 << endl;
  return 0;
}
