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

    string res = "";
    for (int i = s.length() - 1; i >= 0; --i) {
        res += s[i];
    }

    cout << res << endl;

    return 0;
}