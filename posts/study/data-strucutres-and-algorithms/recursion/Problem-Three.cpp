#include <bits/stdc++.h>

using namespace std;

long long fib(long long n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

int main() {
	long long n;
	cin >> n;
	cout << fib(n) << endl;
	return 0;
}
