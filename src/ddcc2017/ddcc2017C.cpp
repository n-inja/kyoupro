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
  int n;
  long long c;
  cin >> n >> c;
  vector<long long> l(n);
  vector<bool> b(n);
  multiset<long long> ms;
  for(int i = 0; i < n; i++) cin >> l[i];
  long long ans = 0;
  for(int i = 0; i < n; i++) ms.insert(l[i]);
  while(ms.size() > 0) {
    auto it = ms.end();
    it--;
    long long now = *it;
    ms.erase(it);
    if(ms.size() == 0) {
      ans++;
      break;
    }
    if(*ms.begin() + now < c) {
      ms.erase(ms.begin());
      ans++;
      continue;
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}
