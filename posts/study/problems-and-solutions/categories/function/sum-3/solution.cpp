#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

double factorial(double x) {
    double res = 1;

    for (int i = 1; i <= x; ++i) {
        res *= i;
    }

    return res;
}

double f(int n) {
    double res = 0;
    for (double i = 1; i <= n; ++i) {
        res += 1.0 / factorial(i);
    }
    return res;
}

int main() {
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("data.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    cout << fixed << setprecision(3) << f(n) << endl;

    return 0;
}