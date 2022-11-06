#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

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

int main() {
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("data.txt", "r", stdin);
    #endif

	vector < int > primes = sieve();
	int queries;
	cin >> queries;
	while (queries--) {
		int n;
		cin >> n;
		cout << primes[n - 1] << endl;
	}

    return 0;
}
