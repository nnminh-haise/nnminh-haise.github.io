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
    vector < int > g(128, 0);
    int f_0 = 1, f_1 = 1, f_2 = 0;
    g[1] = 2;

    for (int i = 3; i <= n; ++i) {
        f_2 = (f_0 + f_1) % 128;
        ++g[f_2];
        f_0 = f_1;
        f_1 = f_2;
    }

    int count = 0;
    int p = 0;
    for (int i = 0; i < 128; ++i) {
        count += g[i];
        if (count >= k) {
            p = i;
            break;
        }
    }
    cout << p << endl;

    return 0;
}