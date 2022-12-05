#include <bits/stdc++.h>

using namespace std;

long long a(int i) {
	if (i == 0) {
		return 1;
	}
	return a(i - 1) + 1;
}

int main() {
	int n;
	cin >> n;
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a(i);
	}
	cout << sum << endl;
	return 0;
}
