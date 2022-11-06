#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void sieveOfEratosthenes() {
    int n = (int)1e6;
    vector < bool > is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p <= n; ++p) {
        if (is_prime[p] == true && (long long)p * p <= n) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (is_prime[i] == true) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    sieveOfEratosthenes();
    return 0;
}