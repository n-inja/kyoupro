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

int n;
vector<int> c, s, f;


int main() {
  cin >> n;
  c.resize(n - 1);
  s.resize(n - 1);
  f.resize(n - 1);
  for(int i = 0; i < n - 1; i++) cin >> c[i] >> s[i] >> f[i];
  for(int i = 0; i < n; i++) {
    int t = 0;
    for(int j = i; j < n - 1; j++) {
      if(t < s[j]) t = s[j] + c[j];
      else {
        t += (f[j] - t % f[j]) % f[j] + c[j];
      }
    }
    cout << t << endl;
  }

  return 0;
}
