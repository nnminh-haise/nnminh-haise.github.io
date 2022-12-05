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
    int *a = new int [n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == k) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;


    return 0;
}