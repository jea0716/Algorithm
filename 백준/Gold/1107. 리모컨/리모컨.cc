#include <iostream>
#include <string>

using namespace std;

int arr[10];

int check(int a)
{
    string d = to_string(a);
    for(int i=0; i<d.length(); i++)
    {
        if(arr[d[i]-'0'])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n; cin >> n;
    int m, tmp; cin >> m;
    for(int i=0; i<m; i++)
    {
        cin >> tmp;
        arr[tmp] = 1;
    }
    int ans = abs(n - 100);
    for(int i=0; i<=1000000; i++)
    {
        if(check(i))
        {
            tmp = abs(n-i) + to_string(i).length();
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}