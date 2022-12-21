#ifndef CREATE_TESTCASES
#define CREATE_TESTCASES

#include <bits/stdc++.h>
#include "libraries/GeneratingMethods.h"
#include "libraries/SideFunctions.h"

using namespace std;

void makeInput(const int testNumber, ofstream& cout) {
	cout << testNumber << endl;

    return;
}

double factorial(double x) {
    double res = 1;

    for (int i = 1; i <= x; ++i) {
        res *= i;
    }

    return res;
}

double f(int n) {
    double res = 0;
    for (double i = 1; i <= n; ++i) {
        res += 1.0 / factorial(i);
    }
    return res;
}

void makeOutput(ifstream& cin, ofstream& cout) {
    int n;
    cin >> n;
    cout << fixed << setprecision(3) << f(n) << endl;
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
