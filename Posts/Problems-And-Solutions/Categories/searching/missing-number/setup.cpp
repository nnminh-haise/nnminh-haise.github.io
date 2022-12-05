#ifndef CREATE_TESTCASES
#define CREATE_TESTCASES

#include <bits/stdc++.h>
#include "libraries/GeneratingMethods.h"
#include "libraries/SideFunctions.h"

using namespace std;

void makeInput(const int testNumber, ofstream& cout) {
	int n = randInt(ClosedSet(100, 10000));
    if (testNumber <= 10) {
        n = randInt(ClosedSet(5, 20));
    }  

    cout << n << endl;
    vector < int > a;
    for (int i = 0; i <= n; ++i) {
        a.push_back(i);
    }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (a.begin(), a.end(), std::default_random_engine(seed));

    int missing_value = randInt(ClosedSet(0, n));
    vector < int > b;
    for (int item: a) {
        if (item != missing_value) {
            b.push_back(item);
        }
    }

    for (int i = 0; i < b.size(); ++i) {
        cout << b[i] << (i < b.size() - 1 ? " " : "\n");
    }

    return;
}

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

void makeOutput(ifstream& cin, ofstream& cout) {
    int n;
    cin >> n;
    vector < int > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << missingNumber(a) << endl;
    return;
}

// ! User can modify this function in order to test your code before you begin to create the testcase.
// ! Otherwise please comment the main() function out! The function below may cause function "redefinition" error!

int main(int agrc, char **agrv) {
    int test_number = 5;

    ofstream testcase_input_data_ostream("test.in");
    ofstream testcase_output_data_ostream("test.out");
    ifstream testcase_input_date_istream("test.in");

    makeInput(test_number, testcase_input_data_ostream);
    makeOutput(testcase_input_date_istream, testcase_output_data_ostream);

    testcase_input_data_ostream.close();
    testcase_output_data_ostream.close();
    testcase_input_date_istream.close();

    return 0;
}

#endif

/*
* 2 1 3 0 4 7 6
* 0 1 2 3 4 5 6
* 0 1 2 3 4 6 7

*/
