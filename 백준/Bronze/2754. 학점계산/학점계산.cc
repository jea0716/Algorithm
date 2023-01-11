#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s; cin >> s;
    if(s == "A+") cout << "4.3" << endl;
    else if(s == "A0") cout << "4.0" << endl;
    else if(s == "A-") cout << "3.7" << endl;
    else if(s == "B+") cout << "3.3" << endl;
    else if(s == "B0") cout << "3.0" << endl;
    else if(s == "B-") cout << "2.7" << endl;
    else if(s == "C+") cout << "2.3" << endl;
    else if(s == "C0") cout << "2.0" << endl;
    else if(s == "C-") cout << "1.7" << endl;
    else if(s == "D+") cout << "1.3" << endl;
    else if(s == "D0") cout << "1.0" << endl;
    else if(s == "D-") cout << "0.7" << endl;
    else cout << "0.0" << endl;
}

/*
A+: 4.3, A0: 4.0, A-: 3.7

B+: 3.3, B0: 3.0, B-: 2.7

C+: 2.3, C0: 2.0, C-: 1.7

D+: 1.3, D0: 1.0, D-: 0.7

F: 0.0
*/