#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

string check(const int *a, const int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] >= a[i + 1]) {
            return "false";
        }
    }
    return "true";
}

int main() {
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("data.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    int *a = new int [n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << check(a, n) << endl;

    return 0;
}