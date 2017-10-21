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
const double mpi = 3.14159265358979323846;

using namespace std;


int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  if(a[n - 1] - a[0] > 1) {
    cout << "No" << endl;
    return 0;
  }
  map<int, int> s;
  for(int i = 0; i < n; i++) s[a[i]]++;
  if(a[0] != a[n - 1] && s[a[0]] + 1 <= a[n - 1] && a[n - 1] <= s[a[0]] + s[a[n - 1]] / 2) {
    cout << "Yes" << endl;
    return 0;
  }
  if(a[0] == a[n - 1]) {
    if(1 <= a[n - 1] && a[n - 1] <= s[a[0]] / 2) {
      cout << "Yes" << endl;
      return 0;
    }
    if(n - 1 == a[0]) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
