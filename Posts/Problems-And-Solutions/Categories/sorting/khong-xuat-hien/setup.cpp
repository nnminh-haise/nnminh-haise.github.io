#ifndef CREATE_TESTCASES
#define CREATE_TESTCASES

#include <bits/stdc++.h>
#include "libraries/GeneratingMethods.h"
#include "libraries/SideFunctions.h"

using namespace std;

void makeInput(const int testNumber, ofstream& cout) {
	int n = randInt(ClosedSet(5, 30000));

    if (testNumber <= 10) {
        n = randInt(ClosedSet(5, 30000));
    }

    cout << n << endl;
    vector < int > a = randList(n, ClosedSet(1, 1000000), false);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i < n - 1 ? " " : "\n");
    }

    return;
}

void makeOutput(ifstream& cin, ofstream& cout) {
    int n;
    cin >> n;
    vector < int > a(n);
    for (int &item: a) {
        cin >> item;
    }

    int *f = new int [1000001];
    for (int i = 0; i <= 1000000; ++i) {
        f[i] = 0;
    }

    for (int item: a) ++f[item];
    for (int i = 0; i <= 1000000; ++i) {
        if (f[i] == 0) {
            cout << i << endl;
            return;
        }
    }
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
