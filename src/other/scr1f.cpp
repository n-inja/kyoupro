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
  vector<int> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  int ans = 1, ma = v[0];
  for(int i=1; i<n;i++){
    if(ma<v[i])ans++;
    ma=max(ma, v[i]);
  }
  cout<<ans<<endl;
  return 0;
}
