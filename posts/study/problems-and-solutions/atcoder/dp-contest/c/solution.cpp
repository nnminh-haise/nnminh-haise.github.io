#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int main() {
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("data.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    int** a = new int* [n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int [3];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    int** dp = new int* [n];
    for (int i = 0; i < n; ++i) {
        dp[i] = new int [3];
    }

    for (int i = 0; i < 3; ++i) {
        dp[0][i] = a[0][i];
    }

    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + a[i][1];
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]) + a[i][2];
    }

    cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << endl;

    return 0;
}