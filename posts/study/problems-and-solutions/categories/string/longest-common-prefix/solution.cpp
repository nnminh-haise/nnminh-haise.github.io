#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int main() {
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("data.txt", "r", stdin);
    #endif

    string s, p;
    cin >> s >> p;
    int i = 0;
    while (i < min(s.length(), p.length()) & s[i] == p[i]) {
        ++i;
    }
    cout << i<< endl;

    return 0;
}