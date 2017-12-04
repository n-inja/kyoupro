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
  vector<int> t(8);
  for(int i = 0; i < 8; i++) cin >> t[i];
  sort(t.begin(), t.end());
  cout << t[7] << endl;

	return 0;
}
