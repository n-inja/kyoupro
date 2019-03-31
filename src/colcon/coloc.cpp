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

long long ans = 0;
vector<vector<int>> p;
long long n;

long long gcd(long long a, long long b) {
  if(a % b == 0) return b;
  return gcd(b, a % b);
}

bool check(unsigned long long bit, int k) {
  return ((bit >> k) & 1) > 0;
}

void dfs(unsigned long long bit, int i) {
  bool b = false;
  for(int j = 0; j < p[i].size(); j++) {
    if(check(bit, p[i][j])) b = true;
  }
  if(i == n - 1) {
    if(!b) ans++;
    ans++;
    return;
  }
  dfs(bit, i + 1);
  if(!b) dfs(bit | (((unsigned long long)1) << i), i + 1);
}

int main() {
  long long a, b;
  cin >> a >> b;
  n = b - a + 1;
  p.resize(n);
  for(long long i = 0; i < n; i++) {
    for(long long j = i + 1; j < n; j++) {
      if(gcd(i + a, j + a) != 1) {
        p[j].push_back(i);
      }
    }
  }

  dfs(0, 0);
  cout << ans << endl;
  return 0;
}
