#include <iostream>
#include <queue>

using namespace std;

int n, m, arr[1005][1005], path[1005][1005], check[1005][1005];

queue<int> q[2];

void bfs()
{
    while(!q[0].empty())
    {
        int x = q[0].front(), y = q[1].front();
        q[0].pop();
        q[1].pop();

        if(arr[x-1][y] == 0 && check[x-1][y] == 0 && x > 0 && x < m + 1 && y > 0 && y < n + 1)
        {
            path[x-1][y] = path[x][y] + 1;
            check[x-1][y] = 1;
            q[0].push(x-1);
            q[1].push(y);
        }
        if(arr[x+1][y] == 0 && check[x+1][y] == 0 && x > 0 && x < m + 1 && y > 0 && y < n + 1)
        {
            path[x+1][y] = path[x][y] + 1;
            check[x+1][y] = 1;
            q[0].push(x+1);
            q[1].push(y);
        }
        if(arr[x][y-1] == 0 && check[x][y-1] == 0 && x > 0 && x < m + 1 && y > 0 && y < n + 1)
        {
            path[x][y-1] = path[x][y] + 1;
            check[x][y-1] = 1;
            q[0].push(x);
            q[1].push(y-1);
        }
        if(arr[x][y+1] == 0 && check[x][y+1] == 0 && x > 0 && x < m + 1 && y > 0 && y < n + 1)
        {
            path[x][y+1] = path[x][y] + 1;
            check[x][y+1] = 1;
            q[0].push(x);
            q[1].push(y+1);
        }
    }
}

int main()
{
    cin >> n >> m;
    int tmp;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> tmp;
            arr[i][j] = tmp;
            if(tmp == 1)
            {
                q[0].push(i);
                q[1].push(j);
                check[i][j] = tmp;
            }
            else if(tmp == -1)
            {
                path[i][j] = -1;
            }
        }
    }

    bfs();

    bool abled = true;
    int answer = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(arr[i][j] == 0 && path[i][j] == 0)
                abled = false;
            if(answer < path[i][j])
                answer = path[i][j];
        }
    }

    if(abled == true)
        cout << answer << endl;
    else
        cout << -1 << endl;
}