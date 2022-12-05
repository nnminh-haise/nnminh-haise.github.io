#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int missingNumber(vector < int > &a) {
    sort(a.begin(), a.end());
    int left = 0, right = a.size();
    while (left < right) {
        int mid = (right - left) / 2 + left;
        if (a[mid] > mid) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("data.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    vector < int > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << missingNumber(a) << endl;

    return 0;
}