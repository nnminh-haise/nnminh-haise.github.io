#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int lowerBound(vector < int > &a, int k) {
    int p = 1e9 + 7;
    int left = 0, right = a.size() - 1;
    while (left <= right) {
        int mid = (right - left + 1) / 2 + left;
        if (k <= a[mid]) {
            p = min(p, mid);
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return p;
}

int main() {
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("data.txt", "r", stdin);
    #endif

    int n, k;
    cin >> n >> k;
    vector < int > a(n);
    for (int &item: a) {
        cin >> item;
    }

    cout << lowerBound(a, k) << endl;

    return 0;
}