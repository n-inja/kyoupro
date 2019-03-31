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
  string s1, s2;
  cin >> s1 >> s2;
  if(s1[0] == 'S' && s2[0] == 'H') cout << "YES" << endl;
  else cout << "NO" << endl;
	return 0;
}
