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
  set<int> s;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int b;
    cin >> b;
    s.insert(b);
  }
  cout << s.size() << endl;
  return 0;
}
