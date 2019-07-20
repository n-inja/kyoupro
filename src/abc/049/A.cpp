#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  char c;
  cin >> c;
  if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') cout << "vowel" << endl;
  else cout << "consonant" << endl;
  return 0;
}
