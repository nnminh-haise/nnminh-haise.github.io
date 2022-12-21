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
        n = randInt(ClosedSet(5, 20));
        m = randInt(ClosedSet(5, 20));
    }

    if (testNumber % 2) {
        string s = randStr(n);
        string str = s;
        sort(str.begin(), str.end());
        next_permutation(str.begin(), str.end());
        cout << s << endl << str << endl;
    }
    else {
        cout << randStr(n) << endl << randStr(m) << endl;
    }

    return;
}

bool isAnagram(string s, string t) {
    if (s.length() != t.length())
        return false;

    vector <unsigned int> f(26, 0);
    for (int i = 0; i < s.length(); ++i) {
        ++f[s[i] - 'a'];
        --f[t[i] - 'a'];
    }

    for (int i = 0; i < s.length(); ++i)
        if (f[s[i] - 'a'] != 0)
            return false;

    return true;
}

void makeOutput(ifstream& cin, ofstream& cout) {
    string s, t;
    cin >> s >> t;
    cout << (isAnagram(s, t) ? "yes\n" : "no\n");
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
