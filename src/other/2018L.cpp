#include <iostream>
#include <string>
using namespace std;
bool solve() {
  string s1, s2;
  cin >> s1;
  if (s1 == "#")
    return false;
  cin >> s2;
  if (s1 < s2)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return true;
}
int main() {
  while (solve())
    ;
  return 0;
}
