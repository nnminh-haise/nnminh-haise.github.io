#ifndef CREATE_TESTCASES
#define CREATE_TESTCASES

#include <bits/stdc++.h>
#include "libraries/GeneratingMethods.h"
#include "libraries/SideFunctions.h"

using namespace std;

void makeInput(const int testNumber, ofstream& cout) {
	int n = randInt(ClosedSet(5, 500));

    if (testNumber <= 10) {
        n = randInt(ClosedSet(5, 10));
    }  

    if (testNumber % 2 == 0) {
        string s = randStr(n);
        string p = s;
        reverse(p.begin(), p.end());

        cout << s << p << endl;
    }
    else {
        cout << randStr(n) << endl;
    }

    return;
}


void makeOutput(ifstream& cin, ofstream& cout) {
    string s;
    cin >> s;
    int n = s.length() - 1;
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        if (s[i] != s[n - i]) {
            flag = false;
        }
    }
    cout << (flag ? "yes\n" : "no\n");

    return;
}

// ! User can modify this function in order to test your code before you begin to create the testcase.
// ! Otherwise please comment the main() function out! The function below may cause function "redefinition" error!

// int main(int agrc, char **agrv) {
//     int test_number = 4;

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
