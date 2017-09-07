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

int power(int e, int x) {
  if(x == 0) return 1;
  if(x == 1) return e;
  return e * power(e, x - 1);
}

int main() {
  int n, k;
  cin >> k >> n;
  vector<pair<string, string>> vw(n);
  for(int i = 0; i < n; i++) cin >> vw[i].first >> vw[i].second;

  int a = power(3, k);

  for(int i = 0; i < a; i++) {
    vector<int> slen(k);
    int b = i;
    for(int j = 0; j < k; j++) {
      slen[j] = b % 3 + 1;
      b /= 3;
    }
    bool c = false;
    for(int j = 0; j < n; j++) {
      int leng = 0;
      for(int k = 0; k < vw[j].first.size(); k++) leng += slen[vw[j].first[k] - '1'];
      if(leng != vw[j].second.size()) c = true;
    }
    if(c) continue;
    vector<string> ans(k);
    for(int j = 0; j < n; j++) {
      int cnt = 0;
      for(int k = 0; k < vw[j].first.size(); k++) {
        if(ans[vw[j].first[k] - '1'] == "") ans[vw[j].first[k] - '1'] = vw[j].second.substr(cnt, slen[vw[j].first[k] - '1']);
        else if(ans[vw[j].first[k] - '1'] != vw[j].second.substr(cnt, slen[vw[j].first[k] - '1'])) c = true;
        cnt += slen[vw[j].first[k] - '1'];
      }
    }
    if(c) continue;
    for(int j = 0; j < k; j++) cout << ans[j] << endl;
    break;
  }
  return 0;
}
