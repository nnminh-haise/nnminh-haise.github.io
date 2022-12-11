#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int main() {
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("data.txt", "r", stdin);
    #endif

    int n, k;
    cin >> n >> k;
    int* a = new int [n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    const int inf = 1e9 + 7;
    int* dp = new int [n];
    for (int i = 0; i < n; ++i) {
        dp[i] = inf;
    }
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i + j < n) {
                dp[i + j] = min(dp[i + j], dp[i] + abs(a[i] - a[i + j]));
            }
        }
    }

    cout << dp[n - 1] << endl;

    return 0;
}