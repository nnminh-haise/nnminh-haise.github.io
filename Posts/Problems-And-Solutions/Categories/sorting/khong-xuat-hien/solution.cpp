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
    vector < int > a(n);
    for (int &item: a) {
        cin >> item;
    }

    int *f = new int [1000001];
    for (int i = 0; i <= 1000000; ++i) {
        f[i] = 0;
    }

    for (int item: a) ++f[item];
    for (int i = 0; i <= 1000000; ++i) {
        if (f[i] == 0) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}