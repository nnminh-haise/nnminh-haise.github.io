#ifndef CREATE_TESTCASES
#define CREATE_TESTCASES

#include <bits/stdc++.h>
#include "libraries/GeneratingMethods.h"
#include "libraries/SideFunctions.h"

using namespace std;

void makeInput(const int testNumber, ofstream& cout) {
	int n = randInt(ClosedSet(5, 1000));
    int m = randInt(ClosedSet(5, 1000));
    if (testNumber <= 10) {
        n = randInt(ClosedSet(5, 10));
        m = randInt(ClosedSet(5, 10));
    }  

    string s = randStr(n);
    string p = randStr(m);
    if (testNumber % 3 == 0 || testNumber % 3 == 1) {
        cout << s << endl << p << endl;
    }
    else {
        cout << s << endl << s << endl;
    }

    return;
}

int compareString(string s, string p) {
    if (s.length() < p.length()) {
        return -1;
    }
    if (s.length() > p.length()) {
        return 1;
    }

    int i = 0, n = s.length();
    while (i < n) {
        if (s[i] < p[i]) {
            return -1;
        }
        else if (s[i] > p[i]) {
            return 1;
        }
        ++i;
    }
    return 0;
}

void makeOutput(ifstream& cin, ofstream& cout) {
    string s, p;
    cin >> s >> p;
    cout << compareString(s, p) << endl;
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
