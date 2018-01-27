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
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	cout << min(max(a[0], l), r);
	for(int i = 1; i < n; i++) {
		cout << " " << min(max(a[i], l), r);
	}
	cout << endl;
	return 0;
}
