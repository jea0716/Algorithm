#include <iostream>
#include <string>

using namespace std;

int arr[65][65];

bool checked(int n, int x, int y)
{
    int value = arr[x][y];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(value != arr[x+i][y+j])
            {
                return false;
            }
        }
    }
    return true;
}

void devide(int n, int x, int y)
{
    if(checked(n, x, y))
    {
        cout << arr[x][y];
        return ;
    }

    cout << '(';
    int half = n / 2;
    devide(half, x, y);
    devide(half, x, y + half);
    devide(half, x + half, y);
    devide(half, x + half, y + half);
    cout << ')';
}

int main()
{
    int n; cin >> n;
    string s;
    for(int i=0; i<n; i++)
    {
        cin >> s;
        int tmp = 0;
        for(int j=0; j<n; j++)
        {
            if(s[j] == '0') arr[i][j] = 0;
            if(s[j] == '1') arr[i][j] = 1;
        }
    }

    devide(n, 0, 0);
    cout << endl;
}