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

vector<int> b(6), c(6);

pair<int, int> f(vector<int> v) {
  pair<int, int> ans;

  for(int i = 0; i < 2; i++) for(int j = 0; j < 3; j++) if(v[3 * i + j] == v[3 * (i + 1) + j]) ans.first += b[i * 3 + j]; else ans.second += b[i * 3 + j];
  for(int i = 0; i < 3; i++) for(int j = 0; j < 2; j++) if(v[3 * i + j] == v[3 * i + j + 1]) ans.first += c[i * 2 + j]; else ans.second += c[i * 2 + j];
  return ans;
}

pair<int, int> g(vector<int> v, int n) {
  if(n == 0) return f(v);
  if(n % 2 == 1) {
    pair<int, int> ans;
    ans.first = -1;
    for(int i = 0; i < 9; i++) {
      vector<int> w = v;
      if(w[i] == 0) {
        w[i] = 1;
        pair<int, int> p = g(w, n - 1);
        if(ans.first < p.first) ans = p;
      }
    }
    return ans;
  } else {
    pair<int, int> ans;
    ans.first = 10000;
    for(int i = 0; i < 9; i++) {
      vector<int> w = v;
      if(w[i] == 0) {
        w[i] = -1;
        pair<int, int> p = g(w, n - 1);
        if(ans.first > p.first) ans = p;
      }
    }
    return ans;
  }
}

int main() {
  for(int i = 0; i < 6; i++) cin >> b[i];
  for(int i = 0; i < 6; i++) cin >> c[i];

  vector<int> v{0, 0, 0, 0, 0, 0, 0, 0, 0};
  pair<int, int> ans = g(v, 9);

  cout << ans.first << endl << ans.second << endl;

  return 0;
}
