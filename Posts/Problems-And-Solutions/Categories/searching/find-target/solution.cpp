#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

vector < int > targetIndices(vector < int > &nums, int target) {
    int low = 1e9 + 7;
    int high = -1;

    sort(nums.begin(), nums.end());

    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = (right - left + 1) / 2 + left;
        if (target <= nums[mid]) {
            if (target == nums[mid]) {
                low = min(low, mid);
            }
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    left = 0;
    right = nums.size() - 1;
    while (left <= right) {
        int mid = (right - left + 1) / 2 + left;
        if (target >= nums[mid]) {
            if (target == nums[mid]) {
                high = max(high, mid);
            }
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    // cerr << "low : " << low << endl;
    // cerr << "high: " << high << endl;

    vector < int > res;
    if (low == 1e9 + 7 || high == -1 || low > high) {
        return res;
    }
    for (int i = low; i <= high; ++i) {
        res.push_back(i);
    }
    return res;
}

int main() {
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("data.txt", "r", stdin);
    #endif

    int n, target;
    cin >> n >> target;
    vector < int > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector < int > res = targetIndices(a, target);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << (i < res.size() - 1 ? " " : "\n");
    }

    return 0;
}