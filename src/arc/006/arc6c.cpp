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
  int n;
  cin >> n;
  vector<int> w(n);
  for(int i = 0; i < n; i++) cin >> w[i];
  multiset<int> field;
  for(int i = 0; i < n; i++) {
    auto it = lower_bound(field.begin(), field.end(), w[i]);
    if(it == field.end()) {
      field.insert(w[i]);
      continue;
    }
    field.erase(it);
    field.insert(w[i]);
  }
  cout << field.size() << endl;
  return 0;
}