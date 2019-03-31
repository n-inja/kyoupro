#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
#include<vector>
#include<math.h>

using namespace std;

vector<long long> prime;

void getPrime(long long r) {
  long long rq = sqrt(r);
  vector<bool> b(rq + 2);
  for(long long i = 2; i <= rq + 1; i++) {
    if(!b[i]) {
      prime.push_back(i);
      for(int j = i * 2; j <= rq + 1; j += i) b[j] = true;
    }
  }
}

bool isPrime(long long x) {
  auto it = lower_bound(prime.begin(), prime.end(), x);
  if(it == prime.end()) return false;
  return x == *it;
}


long long nibu(long long x, long long p) {
  long long mini = 1, maxi = x;
  if(p >= x) return 1;
  while(maxi - mini > 1) {
    long long m = (mini + maxi) / 2;
    if(p * m >= x) maxi = m;
    else mini = m;
  }
  return maxi;
}

int main() {
  long long l, r;
  cin >> l >> r;
  getPrime(r);

  long long ans = 0;
  vector<int> factors(r - l + 1);
  vector<long long> x(r - l + 1);
  for(int i = 0; i < r - l + 1; i++) factors[i] = x[i] = 1;
  for(int i = 0; i < prime.size(); i++) {
    for(long long p = prime[i]; p <= r; p *= prime[i]) {
      long long j = nibu(l, p);
      for(; p * j <= r; j++) {
        x[p * j - l] *= prime[i];
        factors[p * j - l]++;
      }
    }
  }

  for(int i = 0; i < r - l + 1; i++) {
    if(x[i] == l + i) factors[i]--;
  //  cout << l + i << " " << factors[i] << endl;
    if(isPrime(factors[i])) ans++;
  }

  cout << ans << endl;
  return 0;
}
