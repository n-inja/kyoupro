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

long long gcd(long long a, long long b) {
  if(b > a) swap(a, b);
  if(a % b == 0) return b;
  return gcd(b, a%b);
}

int main() {
  long long n, m;
  cin >> n >> m;
  long long g = gcd(n, m);
  if(g == 1) cout << m - 1 << endl;
  else if(m == g) cout << 0 << endl;
  else cout << (m / g - 1) * g << endl;
	return 0;
}
