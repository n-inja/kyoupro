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

int main() {
  string s;
  int k, n;
  cin >> s >> k;
  n = s.size();
  for(int i = 0; i < n; i++) {
    if('z' - s[i] + 1 <= k && s[i] > 'a') {
      k -= 'z' - s[i] + 1;
      s[i] = 'a';
    }
  }
  k %= 26;
  s[n - 1] = (s[n - 1] - 'a' + k) % 26 + 'a';
  cout << s << endl;
	return 0;
}
