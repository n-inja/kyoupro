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

long long P = 1777777777;

long long pow(long long e, long long x) {
  if(x == 0) return 1;
  if(x == 1) return e % P;
  if(x % 2 == 0) return pow((e * e) % P, x / 2);
  return (e * pow(e % P, x - 1)) % P;
}

long long inv(long long a) {
  return pow(a, P - 2);
}

int main() {
  long long n, k;
  cin >> n >> k;
  
  long long comb[k + 1];
  comb[0] = 1;
  for(int i = 1; i <= k; i++) {
    comb[i] = ((comb[i - 1] * ((n - i + 1) % P)) % P * inv(i)) % P;
  }
  
  long long dp[k + 2];
  dp[0] = 0;
  dp[1] = 0;
  dp[2] = 1;
  for(int i = 3; i < k + 2; i++) {
    dp[i] = ((i - 1) * ((dp[i - 1] + dp[i - 2]) % P)) % P;
  }
  
  cout << (comb[k] * dp[k]) % P << endl;
  return 0;
}