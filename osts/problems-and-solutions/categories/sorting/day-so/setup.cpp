#ifndef CREATE_TESTCASES
#define CREATE_TESTCASES

#include <bits/stdc++.h>
#include "libraries/GeneratingMethods.h"
#include "libraries/SideFunctions.h"

using namespace std;

void makeInput(const int testNumber, ofstream& cout) {
	int n = randInt(ClosedSet(3, 1000000));
    int k = randInt(ClosedSet(1, n));

    if (testNumber <= 10) {
        n = randInt(ClosedSet(3, 20));
        k = randInt(ClosedSet(1, n));
    }

    cout << n << " " << k << endl;

    return;
}

void makeOutput(ifstream& cin, ofstream& cout) {
    int n, k;
    cin >> n >> k;
    vector < int > g(128, 0);
    int f_0 = 1, f_1 = 1, f_2 = 0;
    g[1] = 2;

    for (int i = 3; i <= n; ++i) {
        f_2 = (f_0 + f_1) % 128;
        ++g[f_2];
        f_0 = f_1;
        f_1 = f_2;
    }

    int count = 0;
    int p = 0;
    for (int i = 0; i < 128; ++i) {
        count += g[i];
        if (count >= k) {
            p = i;
            break;
        }
    }
    cout << p << endl;


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
