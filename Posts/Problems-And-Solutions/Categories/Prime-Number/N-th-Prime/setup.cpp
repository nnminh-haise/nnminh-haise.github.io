#ifndef CREATE_TESTCASES
#define CREATE_TESTCASES

#include <bits/stdc++.h>
#include "libraries/GeneratingMethods.h"
#include "libraries/SideFunctions.h"

using namespace std;

void makeInput(const int testNumber, ofstream& cout) {
	ClosedSet Q = ClosedSet(1, 1);
	ClosedSet N = ClosedSet(1, (int)1e5);

	if (testNumber > 10) {
		Q = ClosedSet(1, 10000);
	}

	int q = randInt(Q);
	cout << q << endl;
	while (q--) {
		cout << randInt(N) << endl;
	}

    return;
}

vector < int > sieve() {
	int n = 2e6;
	vector < int > res, is_prime(n + 1, 1);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; ++i) {
		if (is_prime[i] == true && (long long)i * i <= n) {
			for (int j = i * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (is_prime[i] == true) {
			res.push_back(i);
		}
	}
	return res;
}

void makeOutput(ifstream& cin, ofstream& cout) {
	vector < int > primes = sieve();
	int queries;
	cin >> queries;
	while (queries--) {
		int n;
		cin >> n;
		cout << primes[n - 1] << endl;
	}    

    return;
}

// ! User can modify this function in order to test your code before you begin to create the testcase.
// ! Otherwise please comment the main() function out! The function below may cause function "redefinition" error!

// int main(int agrc, char **agrv) {
//     int test_number = 5;

//     ofstream testcase_input_data_ostream("test.in");
//     ofstream testcase_output_data_ostream("test.out");
//     ifstream testcase_input_date_istream("test.in");

//     makeInput(test_number, testcase_input_data_ostream);
//     makeOutput(testcase_input_date_istream, testcase_output_data_ostream);

//     testcase_input_data_ostream.close();
//     testcase_output_data_ostream.close();
//     testcase_input_date_istream.close();

//     return 0;
// }

#endif
