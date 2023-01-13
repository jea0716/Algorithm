#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int arr[30][30], check[30][30], path[30][30] = {1, };
vector <int> v;

void bfs(int n, int m)
{
    queue <int> q[2];
    q[0].push(n); q[1].push(m);
    check[n][m] = 1;
    int tmp = 1;
    while(!q[0].empty())
    {
        int x = q[0].front(), y = q[1].front();
        q[0].pop(); q[1].pop();
        if(arr[x-1][y] == 1 && check[x-1][y] == 0)
        {
            check[x-1][y] = 1;
            path[x-1][y] = path[x][y] + 1; tmp++;
            q[0].push(x-1); q[1].push(y);
        }
        if(arr[x+1][y] == 1 && check[x+1][y] == 0)
        {
            check[x+1][y] = 1;
            path[x+1][y] = path[x][y] + 1; tmp++;
            q[0].push(x+1); q[1].push(y);
        }
        if(arr[x][y-1] == 1 && check[x][y-1] == 0)
        {
            check[x][y-1] = 1;
            path[x][y-1] = path[x][y] + 1; tmp++;
            q[0].push(x); q[1].push(y-1);
        }
        if(arr[x][y+1] == 1 && check[x][y+1] == 0)
        {
            check[x][y+1] = 1;
            path[x][y+1] = path[x][y] + 1; tmp++;
            q[0].push(x); q[1].push(y+1);
        }
    }
    v.push_back(tmp);
}

int main()
{
    int n; cin >> n;

    for(int i=0; i<n; i++)
    {
        string s; cin >> s;
        for(int j=0; j<n; j++)
        {
            if(s[j] == '0') arr[i+1][j+1] = 0;
            else arr[i+1][j+1] = 1;
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(arr[i][j] == 1 && check[i][j] == 0) bfs(i, j);
        }
    }

    sort(v.begin(), v.begin()+v.size());
    cout << v.size() << endl;
    for(int i=0; i<v.size(); i++) cout << v[i] << endl;
}