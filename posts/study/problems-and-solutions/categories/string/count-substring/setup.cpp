#ifndef CREATE_TESTCASES
#define CREATE_TESTCASES

#include <bits/stdc++.h>
#include "libraries/GeneratingMethods.h"
#include "libraries/SideFunctions.h"

using namespace std;

void makeInput(const int testNumber, ofstream& cout) {
	int n = randInt(ClosedSet(300, 500));
    int m = randInt(ClosedSet(5, 200));
    if (testNumber <= 10) {
        n = randInt(ClosedSet(20, 30));
        m = randInt(ClosedSet(5, 10));
    }

    string s = randStr(n);
    string p = randStr(m);

    if (testNumber % 2 == 0) {
        int rep = randInt(ClosedSet(1, 20));
        s = "";
        for (int i = 0; i < rep; ++i) {
            s += p;
        }
        cout << s << endl << p << endl;
    }
    else {
        cout << s << endl << p << endl;
    }

    return;
}


void makeOutput(ifstream& cin, ofstream& cout) {
    string s, p;
    cin >> s >> p;
    int ans = 0;
    for (int i = 0; i < s.length() - p.length() + 1; ++i) {
        if (s[i] == p[0]) {
            bool flag = true;
            for (int j = 0; j < p.length(); ++j) {
                if (s[i + j] != p[j]) {
                    flag = false;
                }
            }
            ans += flag;
        }
    }

    cout << ans << endl;
    return;
}

// ! User can modify this function in order to test your code before you begin to create the testcase.
// ! Otherwise please comment the main() function out! The function below may cause function "redefinition" error!

// int main(int agrc, char **agrv) {
//     int test_number = 38;

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
