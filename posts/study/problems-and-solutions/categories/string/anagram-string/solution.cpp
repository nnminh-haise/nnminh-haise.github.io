#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length())
        return false;

    vector <unsigned int> f(26, 0);
    for (int i = 0; i < s.length(); ++i) {
        ++f[s[i] - 'a'];
        --f[t[i] - 'a'];
    }

    for (int i = 0; i < s.length(); ++i)
        if (f[s[i] - 'a'] != 0)
            return false;

    return true;
}

int main() {
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("data.txt", "r", stdin);
    #endif

    string s, t;
    cin >> s >> t;
    cout << (isAnagram(s, t) ? "yes\n" : "no\n");

    return 0;
}