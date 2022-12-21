#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int main() {
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("data.txt", "r", stdin);
    #endif

    int ans = 0;
    string s, p;
    cin >> s >> p;
    for (int i = 0; i < s.length() - p.length() + 1; ++i) {
        if (s[i] == p[0]) {
            bool flag = true;
            for (int j = 0; j < p.length(); ++j) {
                if (s[i + j] != p[j]) {
                    flag = false;
                }
            }
            ans += flag;
        }
    }

    cout << (ans == 0 ? "no\n" : "yes\n");

    return 0;
}