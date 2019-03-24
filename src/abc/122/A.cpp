#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  char c;
  cin >> c;
  if (c == 'A')
    cout << 'T';
  else if (c == 'T')
    cout << 'A';
  else if (c == 'C')
    cout << 'G';
  else
    cout << 'C';
  cout << endl;
  return 0;
}
