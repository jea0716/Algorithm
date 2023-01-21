#include <iostream>

using namespace std;

int main()
{
    int sum; cin >> sum;

    int n; cin >> n;
    int item, cnt; 
    for(int i=0; i<n; i++)
    {
        cin >> item >> cnt;
        sum -= item * cnt;
    }

    if(sum == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}