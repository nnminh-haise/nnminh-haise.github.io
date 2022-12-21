#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int compareString(string s, string p) {
    if (s.length() < p.length()) {
        return -1;
    }
    if (s.length() > p.length()) {
        return 1;
    }

    int i = 0, n = s.length();
    while (i < n) {
        if (s[i] < p[i]) {
            return -1;
        }
        else if (s[i] > p[i]) {
            return 1;
        }
        ++i;
    }
    return 0;
}

int main() {
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("data.txt", "r", stdin);
    #endif

    string s, p;
    cin >> s >> p;
    cout << compareString(s, p) << endl;

    return 0;
}