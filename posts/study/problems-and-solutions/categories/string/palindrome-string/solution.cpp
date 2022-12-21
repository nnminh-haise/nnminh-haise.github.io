#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int main() {
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("data.txt", "r", stdin);
    #endif

    string s;
    cin >> s;
    int n = s.length() - 1;
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        if (s[i] != s[n - i]) {
            flag = false;
        }
    }
    cout << (flag ? "yes\n" : "no\n");

    return 0;
}