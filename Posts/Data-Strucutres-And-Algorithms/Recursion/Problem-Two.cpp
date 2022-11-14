#include <bits/stdc++.h>

using namespace std;

long long f(long long x) {
	if (x == 1 || x == 0) {
		return 1;
	}
	return x * f(x - 1);
}

int main() {
	long long n;
	cin >> n;
	cout << f(n) << endl;
	return 0;
}
