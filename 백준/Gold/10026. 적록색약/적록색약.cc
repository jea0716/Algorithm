#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, arr[105][105], arr2[105][105], check[105][105], check2[105][105];

void bfs(int x, int y, int c)
{
    queue<int> q[2];
    q[0].push(x); q[1].push(y);
    check[x][y] = 1;

    while(!q[0].empty())
    {
        int a = q[0].front(), b = q[1].front();
        q[0].pop(); q[1].pop();

        if(check[a-1][b] == 0 && arr[a-1][b] == c)
        {
            q[0].push(a-1); q[1].push(b);
            check[a-1][b] = 1;
        }
        if(check[a+1][b] == 0 && arr[a+1][b] == c)
        {
            q[0].push(a+1); q[1].push(b);
            check[a+1][b] = 1;
        }
        if(check[a][b-1] == 0 && arr[a][b-1] == c)
        {
            q[0].push(a); q[1].push(b-1);
            check[a][b-1] = 1;
        }
        if(check[a][b+1] == 0 && arr[a][b+1] == c)
        {
            q[0].push(a); q[1].push(b+1);
            check[a][b+1] = 1;
        }
    }
}

void bfs2(int x, int y, int c)
{
    queue<int> q2[2];
    q2[0].push(x); q2[1].push(y);
    check2[x][y] = 1;

    while(!q2[0].empty())
    {
        int a = q2[0].front(), b = q2[1].front();
        q2[0].pop(); q2[1].pop();

        if(check2[a-1][b] == 0 && arr2[a-1][b] == c)
        {
            q2[0].push(a-1); q2[1].push(b);
            check2[a-1][b] = 1;
        }
        if(check2[a+1][b] == 0 && arr2[a+1][b] == c)
        {
            q2[0].push(a+1); q2[1].push(b);
            check2[a+1][b] = 1;
        }
        if(check2[a][b-1] == 0 && arr2[a][b-1] == c)
        {
            q2[0].push(a); q2[1].push(b-1);
            check2[a][b-1] = 1;
        }
        if(check2[a][b+1] == 0 && arr2[a][b+1] == c)
        {
            q2[0].push(a); q2[1].push(b+1);
            check2[a][b+1] = 1;
        }
    }
}

int main()
{
    cin >> n;
    string s;
    for(int i=1; i<=n; i++)
    {
        cin >> s;
        for(int j=0; j<s.length(); j++)
        {
            if(s[j] == 'R')
            {
                arr[i][j+1] = 1; arr2[i][j+1] = 1;
            }
            else if(s[j] == 'G')
            {
                arr[i][j+1] = 2; arr2[i][j+1] = 1;
            }
            else if(s[j] == 'B')
            {
                arr[i][j+1] = 3; arr2[i][j+1] = 3;
            }
        }
    }

    int answer = 0, answer2 = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(check[i][j] == 0)
            {
                bfs(i, j, arr[i][j]);
                answer++;
            }
            if(check2[i][j] == 0)
            {
                bfs2(i, j, arr2[i][j]);
                answer2++;
            }
        }
    }

    cout << answer << " " << answer2 << endl;

    return 0;
}