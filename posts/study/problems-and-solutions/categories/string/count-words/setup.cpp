#ifndef CREATE_TESTCASES
#define CREATE_TESTCASES

#include <bits/stdc++.h>
#include "libraries/GeneratingMethods.h"
#include "libraries/SideFunctions.h"

using namespace std;

void makeInput(const int testNumber, ofstream& cout) {
	int n = randInt(ClosedSet(5, 1000));
    if (testNumber <= 10) {
        n = randInt(ClosedSet(5, 20));
    }

    if (testNumber == 1) {
        cout << " \n";
    }
    else if (testNumber == 2) {
        cout << "       \n";
    }
    else {
        string tmp = "q we r ty u io pa s df g hj klz xc vb n m";
        cout << randStr(n, tmp) << endl;
    }

    return;
}


void makeOutput(ifstream& cin, ofstream& cout) {
    string s;
    getline(cin, s);

    int ans = 0;
    int i = 0;
    while (i < s.length()) {
        string tmp = "";
        while (s[i] != ' ') {
            tmp += s[i++];
        }
        ++i;
        if (tmp.length() != 0) {
            ++ans;
        }
    }

    cout << ans << endl;
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
