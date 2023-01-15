#include <iostream>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    while(n != 0 && m != 0)
    {
        if(m < n) cout << "Yes" << endl;
        else cout << "No" << endl;
        cin >> n >> m;
    }
}