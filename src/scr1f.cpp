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
  vector<long long> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  vector<long long> dp(n), l(n);
  l[0] = v[0];
  int id = 1;
  for(int i = 1; i < n; i++) if(l[id - 1] < v[i]) l[id++] = v[i];
    else {
      auto it =
    }

  return 0;
}
