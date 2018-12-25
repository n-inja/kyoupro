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

#define P 1000000007

using namespace std;

class Counting {
	unsigned long long p, n;
	vector<long long> invMemo, facMemo, facInvMemo;
public:
	Counting(unsigned long long nn, unsigned long long np) {
		p = np;
		n = nn;
		invMemo.resize(n + 1);
		facMemo.resize(n + 1);
		facInvMemo.resize(n + 1);
		facMemo[0] = 1;
		facMemo[1] = 1;
		facInvMemo[0] = 1;
		facInvMemo[1] = 1;
		invMemo[0] = 0;
		invMemo[1] = 1;
		for (unsigned long long i = 2; i <= n; i++) {
			invMemo[i] = p - (p / i)*invMemo[p%i] % p;
			facMemo[i] = (facMemo[i - 1] * i) % p;
			facInvMemo[i] = (facInvMemo[i - 1] * invMemo[i]) % p;
		}
	}
	unsigned long long fac(unsigned long long k) {
		return facMemo[k];
	}
	unsigned long long facInv(unsigned long long k) {
		return facInvMemo[k];
	}
	unsigned long long choose(unsigned long long n, unsigned long long k) {
		if (!(0 <= k && k <= n))
			return 0;
		return (((facMemo[n] * facInvMemo[k]) % p)*facMemo[n - k]) % p;
	}
	unsigned long long divide(unsigned long long a, unsigned long long b) {
		return (a * invMemo[b]) % p;
	}
	unsigned long long mod(unsigned long long a) {
		a %= p;
		if (a < 0) a += p;
		return a;
	}
	unsigned long long power(unsigned long long a, unsigned long long e) {
		unsigned long long ans = 1;
		for (; e > 0; e /= 2) {
			if (e % 2 != 0)
				ans = ans * a % p;
			a = a*a%p;
		}
		return ans;
	}
};

class Node {
public:
	long long c, d;
	int now;
	Node(int nn, long long cc, long long dd) {
		c = cc;
		now = nn;
		d = dd;
	}
	bool operator<(const Node &rhs) const {
		return this->d < rhs.d;
	}
	bool operator>(const Node &rhs) const {
		return this->d > rhs.d;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<map<long long, vector<pair<int, int>>>> p;
	p.resize(n);
	for (int i = 0; i < m; i++) {
		int to, from, c;
		cin >> to >> from >> c;
		to--; from--;
		pair<int, int> sta1(from, c);
		pair<int, int> sta2(to, c);
		p[to][c].push_back(sta1);
		p[from][c].push_back(sta2);
	}

	Node start(0, 0, 0);
	multiset<Node> queue;
	queue.insert(start);
	vector<map<int, bool>> b;
	b.resize(n);
	int ans = -1;
	while (queue.size() > 0) {
		Node now = *queue.begin();
		queue.erase(queue.begin());
		//cout << now.now + 1 <<  " " << now.c << " " << now.d << endl;

		if (now.now == n - 1) {
			ans =  now.d;
			break;
		}
		if (b[now.now][now.c]) {
			continue;
		}
		b[now.now][now.c] = true;
		for (int i = 0; i < p[now.now][now.c].size(); i++) {
			if (b[p[now.now][now.c][i].first][p[now.now][now.c][i].second]) {
				continue;
			}
			Node next(p[now.now][now.c][i].first, now.c, now.d);
			queue.insert(next);
		}
		if (!b[now.now][0]) {
			Node next(now.now, 0, now.d);
			queue.insert(next);
		}
		if (now.c == 0) {
			for (auto it = p[now.now].begin(); it != p[now.now].end(); it++) {
				for (int i = 0; i < it->second.size(); i++) {
					if (b[it->second[i].first][it->second[i].second]) {
						continue;
					}
					Node next(it->second[i].first, it->second[i].second, now.d + 1);
					queue.insert(next);
				}
			}
		}
	}
	cout << ans << endl;
	//cin >> n;
	return 0;
}
