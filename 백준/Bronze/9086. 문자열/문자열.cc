#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n; cin >> n;
    for(int i=0; i<n; i++)
    {
        string s; cin >> s;
        cout << s[0];
        cout << s.back() << endl;
    }
}