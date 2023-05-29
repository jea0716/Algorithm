#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    string s; cin >> s;
    string a = "";
    for(int i=s.length()-1; i>=0; i=i-3)
    {
        int tmp = 0;
        for(int j=0; j<3; j++)
        {
            if(s[i-j] == '1') tmp += pow(2, j);
        }
        a.append(to_string(tmp));
    }

    reverse(a.begin(), a.end());
    cout << a << endl;
    return 0;
}