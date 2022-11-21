#include <bits/stdc++.h>

using namespace std;

void backtracking(const int n, int index, int*& x) {
	if (index == n) {
		for (int i = 0; i < n; ++i) {
			cout << x[i];
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i <= 1; ++i) {
		x[index] = i;
		backtracking(n, index + 1, x);
	}
}

int main() {
	int n;
	cin >> n;
	int* x = new int [n];
	backtracking(n, 0, x);
	delete[] x;
	return 0;
}
