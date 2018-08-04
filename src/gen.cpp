#include <iostream>
using namespace std;
int main() {
  cout << "1000 1000 100000" << endl;
  cout << "UDLR";
  for (int i = 4; i < 100000; i++)
    cout << "L";
  cout << endl;
  cout << "S";
  for (int i = 1; i < 1000; i++)
    cout << ".";
  cout << endl;
  for (int i = 1; i < 999; i++) {
    for (int j = 0; j < 1000; j++)
      cout << ".";
    cout << endl;
  }
  for (int i = 1; i < 1000; i++) {
    cout << ".";
  }
  cout << "G" << endl;
  return 0;
}
