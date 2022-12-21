#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int main() {
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("data.txt", "r", stdin);
    #endif

    string s;
    getline(cin, s);

    int ans = 0;
    int i = 0;
    while (i < s.length()) {
        string tmp = "";
        while (s[i] != ' ') {
            tmp += s[i++];
        }
        ++i;
        if (tmp.length() != 0) {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}