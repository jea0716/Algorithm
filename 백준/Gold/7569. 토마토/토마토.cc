#include <iostream>
#include <queue>

using namespace std;

int n, m, h;
int arr[105][105][105], check[105][105][105], path[105][105][105];

queue<int> q[3];

void bfs()
{
    while(!q[0].empty())
    {
        int a = q[0].front(), b = q[1].front(), c = q[2].front();
        q[0].pop(); q[1].pop(); q[2].pop();

        if(arr[a-1][b][c] == 0 && check[a-1][b][c] == 0 && a > 0 && b > 0 && c > 0 && a <= m && b <= n && c <= h)
        {
            path[a-1][b][c] = path[a][b][c] + 1;
            check[a-1][b][c] = 1;
            arr[a-1][b][c] = 1;
            q[0].push(a-1); q[1].push(b); q[2].push(c);
        }
        if(arr[a+1][b][c] == 0 && check[a+1][b][c] == 0 && a > 0 && b > 0 && c > 0 && a <= m && b <= n && c <= h)
        {
            path[a+1][b][c] = path[a][b][c] + 1;
            check[a+1][b][c] = 1;
            arr[a+1][b][c] = 1;
            q[0].push(a+1); q[1].push(b); q[2].push(c);
        }
        if(arr[a][b-1][c] == 0 && check[a][b-1][c] == 0 && a > 0 && b > 0 && c > 0 && a <= m && b <= n && c <= h)
        {
            path[a][b-1][c] = path[a][b][c] + 1;
            check[a][b-1][c] = 1;
            arr[a][b-1][c] = 1;
            q[0].push(a); q[1].push(b-1); q[2].push(c);
        }
        if(arr[a][b+1][c] == 0 && check[a][b+1][c] == 0 && a > 0 && b > 0 && c > 0 && a <= m && b <= n && c <= h)
        {
            path[a][b+1][c] = path[a][b][c] + 1;
            check[a][b+1][c] = 1;
            arr[a][b+1][c] = 1;
            q[0].push(a); q[1].push(b+1); q[2].push(c);
        }
        if(arr[a][b][c-1] == 0 && check[a][b][c-1] == 0 && a > 0 && b > 0 && c > 0 && a <= m && b <= n && c <= h)
        {
            path[a][b][c-1] = path[a][b][c] + 1;
            check[a][b][c-1] = 1;
            arr[a][b][c-1] = 1;
            q[0].push(a); q[1].push(b); q[2].push(c-1);
        }
        if(arr[a][b][c+1] == 0 && check[a][b][c+1] == 0 && a > 0 && b > 0 && c > 0 && a <= m && b <= n && c <= h)
        {
            path[a][b][c+1] = path[a][b][c] + 1;
            check[a][b][c+1] = 1;
            arr[a][b][c+1] = 1;
            q[0].push(a); q[1].push(b); q[2].push(c+1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> h;
    int tmp;

    for(int k=1; k<=h; k++)
    {
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                cin >> tmp;
                arr[i][j][k] = check[i][j][k] = tmp;
                if(tmp == 1)
                {
                    q[0].push(i); q[1].push(j); q[2].push(k);
                }
                if(tmp == -1)
                {
                    path[i][j][k] = -1;
                }
            }
        }
    }

    bfs();

    bool abled = true;
    int answer = -1;

    for(int k=1; k<=h; k++)
    {
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(arr[i][j][k] == 0 && check[i][j][k] == 0)
                {
                    abled = false;
                }
                if(answer < path[i][j][k]) answer = path[i][j][k];
            }
        }
    }

    if(abled == true) cout << answer << '\n';
    else cout << -1 << '\n';

    return 0;
}