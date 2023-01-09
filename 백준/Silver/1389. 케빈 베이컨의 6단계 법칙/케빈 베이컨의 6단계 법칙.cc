#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kevin[101];
int kevin_num[101];

vector <int> v[101];
int check[101];

void bfs(int s)
{   
    for(int i=0; i<101; i++) kevin[i] = 0;
    queue <int> q;
    q.push(s);
    check[s] = 1;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i=0; i<v[x].size(); i++)
        {
            int y = v[x][i];
            if(check[y] == 0)
            {
                q.push(y);
                check[y] = 1;
                kevin[y] = kevin[x] + 1;
            }
        }
    }
    int sum = 0;
    for(int i=0; i<101; i++) sum += kevin[i];
    kevin_num[s] = sum;
}

int main()
{
    int n, m; cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int x, y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) check[j] = 0;
        bfs(i);
    }

    int ans = 0, min_num = 9999;
    for(int i=1; i<=n; i++)
    {
        if(kevin_num[i] < min_num)
        {
            ans = i; min_num = kevin_num[i];
        }
    }
    cout << ans << '\n';

    return 0;
}