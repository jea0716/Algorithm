#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int arr[101][101], check[101][101], path[101][101], n;

int main()
{
    int tmp;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            cin >> tmp;
            if(tmp == 0) arr[i][j] = 9999;
            else
                arr[i][j] = tmp;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = (arr[i][j] < arr[i][k] + arr[k][j]) ? arr[i][j] : (arr[i][k] + arr[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j] != 9999)
                cout << 1 << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
}