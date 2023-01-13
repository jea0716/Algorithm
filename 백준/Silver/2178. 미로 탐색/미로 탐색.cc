#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int arr[102][102], check[102][102], path[102][102];
int n, m, answer;

void bfs(int a, int b)
{
    queue <int> q[2];
    q[0].push(a);
    q[1].push(b);
    check[a][b] = 1;
    while(!q[0].empty())
    {
        int x = q[0].front(), y = q[1].front();
        if(n == x && m == y) break;
        q[0].pop(); q[1].pop();

        if(arr[x-1][y] == 1 && check[x-1][y] == 0)
        {
            q[0].push(x-1); q[1].push(y);
            check[x-1][y] = 1;
            path[x-1][y] = path[x][y] + 1;
        }
        if(arr[x+1][y] == 1 && check[x+1][y] == 0)
        {
            q[0].push(x+1); q[1].push(y);
            check[x+1][y] = 1;
            path[x+1][y] = path[x][y] + 1;
        }
        if(arr[x][y-1] == 1 && check[x][y-1] == 0)
        {
            q[0].push(x); q[1].push(y-1);
            check[x][y-1] = 1;
            path[x][y-1] = path[x][y] + 1;
        }
        if(arr[x][y+1] == 1 && check[x][y+1] == 0)
        {
            q[0].push(x); q[1].push(y+1);
            check[x][y+1] = 1;
            path[x][y+1] = path[x][y] + 1;
        }
    }
}

int main()
{
    int n, m; cin >> n >> m;
    char width[m+1];
    for(int i=1; i<=n; i++)
    {
        cin >> width;
        for(int j=0; j<m; j++)
        {
            if(width[j] == '0') arr[i][j+1] = 0;
            else arr[i][j+1] = 1;
        }
    }

    bfs(1, 1);

    cout << path[n][m] + 1 << endl;

    return 0;
}