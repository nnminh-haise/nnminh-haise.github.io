#ifndef SOLUTION_H
#define SOLUTION_H

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

class Solution {
private:

public:
    void recursion(const int n, int index, int *x) {
        if (index == n) {
            for (int i = 0; i < n; ++i) {
                cout << x[i] << (i < n - 1 ? " " : "\n");
            }
            return;
        }
        for (int i = 0; i <= 1; ++i) {
            x[index] = i;
            recursion(n, index + 1, x);
        }
    }

    Solution() {
        int n;
        cin >> n;
        int *x = new int [n];
        recursion(n, 0, x);
    }
};

int main(int agrc, char **agrv) {
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("data.txt", "r", stdin);
    #endif

    Solution sol;

    return 0;
}

#endif