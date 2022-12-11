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
    int* a = new int [n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int* f = new int [n];
    f[0] = 0;
    f[1] = abs(a[0] - a[1]);
    for (int i = 2; i < n; ++i) {
        f[i] = min(f[i - 1] + abs(a[i - 1] - a[i]), f[i - 2] + abs(a[i - 2] - a[i]));
    }
    cout << f[n - 1] << endl;

    return 0;
}