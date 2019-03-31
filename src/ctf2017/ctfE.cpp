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

vector<int> cor;

long long power(int a, int b) {
  if(b == 0) return 1;
  if(b == 1) return a;
  if(b % 2 == 0) return power(a * a, b / 2);
  else return a * power(a, b - 1);
}

void solve(int w, int n, int off) {
  int m = power(5, n);
  int h[5] = {8, 9, 10, 11, 12};
  for(int i = 0; i < m; i++) {
    int sum = 0;
    for(int j = 0; j < n; j++) {
      int a = power(10, j) * h[(i / power(5, j)) % 5];
      sum += a;
    }
    if(sum == w) {
      for(int j = 0; j < n; j++) if(((i / power(5, j)) % 5) % 2 == 0) cor[off + j] = 0;
      else cor[off + j] = 1;
    }
  }
}

int main() {
  int n;
  cin >> n;
  cor.resize(n);
  for(int i = 0; i < n / 5; i++) {
    vector<int> q(n);
    for(int j = 0; j < 5; j++) q[j + i * 5] = power(10, j);

    cout << "? " << q[0];
    for(int j = 1; j < n; j++) cout << " " << q[j];
    cout << endl;

    int ans;
    cin >> ans;
    solve(ans, 5, i * 5);
  }
  if(n % 5 > 0) {
    vector<int> q(n);
    int off = n / 5 * 5;
    for(int i = 0; i < n % 5; i++) q[off + i] = power(10, i);

    cout << "? " << q[0];
    for(int i = 1; i < n; i++) cout << " " << q[i];
    cout << endl;

    int ans;
    cin >> ans;
    solve(ans, n % 5, off);
  }
  cout << "! " << cor[0];
  for(int i = 1; i < n; i++) cout << " " << cor[i];
  cout << endl;
	return 0;
}
