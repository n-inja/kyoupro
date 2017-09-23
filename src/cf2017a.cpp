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
  cin >> s;
  if(s.substr(0, 4) == "YAKI") cout << "Yes" << endl;
  else cout << "No" << endl;
	return 0;
}
