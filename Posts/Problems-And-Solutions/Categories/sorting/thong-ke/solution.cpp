#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int countDistinctValues(vector < int > arr) {
    int res = 1;

    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] != arr[i]) {
            ++res;
        }
    }

    return res;
}

int highestFrequency(vector < int > arr) {
    int res = -1;
    int count = 0;
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] != arr[i]) {
            count = 1;
        }
        else {
            ++count;
        }

        if (count > res) {
            res = count;
        }
    }
    return res;
}

int main() {
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("data.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    vector < int > a(n);
    for (int &item: a) {
        cin >> item;
    }

    sort(a.begin(), a.end());
    cout << countDistinctValues(a) << endl;
    cout << highestFrequency(a) << endl;



    return 0;
}