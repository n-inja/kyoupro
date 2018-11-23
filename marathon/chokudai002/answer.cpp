#include <algorithm>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <random>
#include <set>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

mt19937 mt(10000000);

vector<int> prime;
long long LIMIT = 1000000000ll;

long long power(long long e, long long x) {
  if (x == 0)
    return 1;
  if (x == 1)
    return e;
  if (x % 2 == 0)
    return power(e * e, x / 2);
  return e * power(e, x - 1);
}

struct Core {
  int p, priority;
  Core() {}
  Core(int i) {
    p = prime[i];
    priority = i + mt() % (prime.size() * 2);
  }
};
bool operator<(const Core &l, const Core &r) { return l.priority > r.priority; }

struct Number {
  Core added;
  long long value;
  Number() { value = 1; }
  multiset<Core> primes;
  multiset<Core> erased;
  void add(Core c) {
    primes.insert(c);
    value *= c.p;
    while (value > LIMIT) {
      Core c = *primes.begin();
      primes.erase(primes.begin());
      value /= c.p;
      erased.insert(c);
    }
  }
  void hop() {
    added = Core(mt() % 100);
    erased.clear();
    add(added);
  }
  void rollback() {
    value /= added.p;
    primes.erase(added);
    for (auto &c : erased) {
      value *= c.p;
      primes.insert(c);
    }
  }
};

struct Node {
  Number nums[100];
  int before;
  int score() {
    vector<long long> vals(100);
    for (int i = 0; i < 100; i++) {
      long long v = nums[i].value;
      if (v > 1000000000ll)
        return 0;
      vals[i] = v;
    }
    set<int> s;
    for (int i = 1; i * i < 1000000000; i++) {
      for (int j = 0; j < 100; j++) {
        if (vals[j] % i == 0) {
          s.insert(i);
          s.insert(vals[j] / i);
        }
      }
    }
    return s.size();
  }
  void hop() {
    before = mt() % 100;
    nums[before].hop();
  }
  void rollback() { nums[before].rollback(); }
};

double prob(double diff, double tmp) { return exp(diff / tmp); }

int main() {
  bool isPrime[200000] = {0};
  for (int i = 2; i < 200000; i++) {
    if (isPrime[i])
      continue;
    prime.push_back(i);
    for (int j = 2; i * j < 200000; j++) {
      isPrime[i * j] = true;
    }
  }
  Node now_state;

  int best_score = now_state.score();
  Node best = now_state;

  chrono::system_clock::time_point start, now;
  start = chrono::system_clock::now();
  double elapsed = 0;
  int cnt = 0;
  int limit = 10000, offset = 100;
  int old_score = 0, score = 0;
  while (limit - offset > elapsed) {
    if (cnt++ % 100 == 0) {
      now = chrono::system_clock::now();
      elapsed =
          chrono::duration_cast<chrono::milliseconds>(now - start).count();
    }
    double T = (limit - elapsed) / limit;

    old_score = score;
    now_state.hop();
    score = now_state.score();
    if (score > best_score) {
      score = best_score;
      best = now_state;
    } else if (score > old_score) {
      // do nothing
    } else {
      double score_diff = score - old_score;
      double p = prob(score_diff, T);
      double q = ((mt() % 10000) / 10000.0);
      if (q > p) {
        now_state.rollback();
      }
    }
  }
  cerr << cnt << " " << best.score() << endl;
  for (int i = 0; i < 100; i++) {
    cout << best.nums[i].value << endl;
  }

  return 0;
}
