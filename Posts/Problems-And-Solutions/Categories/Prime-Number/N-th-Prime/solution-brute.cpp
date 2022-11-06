#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }

    if (n == 2 || n == 3) {
        return true;
    }

    if (n % 2 == 0) {
        return false;
    }

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
	int queries;
    cin >> queries;
    while (queries--) {
        int n, p = 1, counter = 0;
        cin >> n;
        while (counter != n) {
            ++p;
            if (is_prime(p) == true) {
                ++counter;
            }
        }
        cout << p << endl;
    }

    return 0;
}
