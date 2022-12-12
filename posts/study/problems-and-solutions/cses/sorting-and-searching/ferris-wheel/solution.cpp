#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int* a = new int [n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);
    int ans = 0, i = 0, j = n - 1;
    int* is_used = new int [n];
    for (int i = 0; i < n; ++i) {
        is_used[i] = false;
    }
    
    while (i < j) {
        if (a[i] + a[j] <= x) {
            is_used[i] = is_used[j] = true;
            ++i;
            --j;
            ++ans;
        }
        else {
            --j;
        }
    }

    for (int i = 0; i < n; ++i) {
        ans += (is_used[i] == false);
    }

    cout << ans << endl;
    return 0;
}
