#include <bits/stdc++.h>

using namespace std;

class Student {
public:
    string name;
    int englishGrade;
};

int main() {
    Student a;
    a.name = "Minh";
    a.englishGrade = 9;

    cout << a.name << endl;
    cout << a.englishGrade << endl;

    return 0;
}