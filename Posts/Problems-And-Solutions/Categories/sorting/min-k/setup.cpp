#ifndef CREATE_TESTCASES
#define CREATE_TESTCASES

#include <bits/stdc++.h>
#include "libraries/GeneratingMethods.h"
#include "libraries/SideFunctions.h"

using namespace std;

void makeInput(const int testNumber, ofstream& cout) {
	int n = randInt(ClosedSet(1, 10000));
    int k = randInt(ClosedSet(1, n));

    if (testNumber <= 10) {
        n = randInt(ClosedSet(1, 20));
        k = randInt(ClosedSet(1, n));
    }

    cout << n << " " << k << endl;
    vector < int > a = randList(n, ClosedSet(1, 10000), true);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i < n - 1 ? " " : "\n");
    }


    return;
}

void makeOutput(ifstream& cin, ofstream& cout) {
    int n, k;
    cin >> n >> k;
    int *a = new int [n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);

    cout << a[k - 1] << endl;
    return;
}

// ! User can modify this function in order to test your code before you begin to create the testcase.
// ! Otherwise please comment the main() function out! The function below may cause function "redefinition" error!

// int main(int agrc, char **agrv) {
//     int test_number = 5;

//     ofstream testcase_input_data_ostream("test.in");
//     ofstream testcase_output_data_ostream("test.out");
//     ifstream testcase_input_date_istream("test.in");

//     makeInput(test_number, testcase_input_data_ostream);
//     makeOutput(testcase_input_date_istream, testcase_output_data_ostream);

//     testcase_input_data_ostream.close();
//     testcase_output_data_ostream.close();
//     testcase_input_date_istream.close();

//     return 0;
// }

#endif
