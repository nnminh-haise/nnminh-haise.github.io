#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <bits/stdc++.h>

using namespace std;

const long double esp = 1e-9;

long long binary_pow(long long a, long long b) {
	if (b == 0) {
		return 1;
	}

	if (b == 1) {
		return a;
	}

	long long tmp = pow(a, b / 2);
	if (b % 2 == 0) {
		return tmp * tmp;
	}

	return tmp * tmp * a;
}


int count_floating_point(long double n) {
	int counter = 0;
	//while (true) {
	//	long long p = ceil(n * pow(10, counter));
	//	long long q = round(n * pow(10, counter));
	//	cerr << "p = " << p << endl;
	//	cerr << "q = " << q << endl;
	//	if (p - q == 0) break;
	//	++counter;
	//}
	while ((long long)ceil(n * pow(10, counter)) != (long long)round(n * pow(10, counter))) {
		++counter;
	}
	return counter;
}

#endif
