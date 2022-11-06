#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

bool check(int x) {
    if (x == 1) {
        return false;
    }

    int counter = 0;
    int p = 2;
    while (x > 1) {
        bool divided = false;
        while (x % p == 0) {
            if (x % p == 0) {
                divided = true;
            }
            x /= p;
        }
        if (divided) {
            ++counter;
        }
        ++p;
    }
    return (counter == 2);
}

int main() {
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("data.txt", "r", stdin);
    #endif

    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (check(i)) {
            ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}
