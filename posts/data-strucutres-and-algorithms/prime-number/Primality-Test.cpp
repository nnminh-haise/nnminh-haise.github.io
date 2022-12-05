#include <iostream>
#include <math.h>

using namespace std;

bool is_prime(int x) {
    if (x < 2) {
        return false;
    }
    if (x == 2 || x == 3) {
        return true;
    }
    if (x % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= sqrt(x); i += 2) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int p = 31;
    cout << is_prime(p) << endl;

    return 0;
}