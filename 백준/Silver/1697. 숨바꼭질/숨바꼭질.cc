#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int check[100001];
int path[100001];

queue <int> q;

void bfs(int s)
{
    path[s] = 0;
    q.push(s);
    check[s] = 1;

    while(!q.empty())
    {
        int x = q.front();
        if(x == m) break;
        q.pop();

        if(check[x+1] == 0 && x+1 >= 0 && x+1 < 100001)
        {
            check[x+1] = 1;
            path[x+1] = path[x] + 1;
            q.push(x+1);
        }
        if(check[x-1] == 0 && x-1 >= 0 && x-1 < 100001)
        {
            check[x-1] = 1;
            path[x-1] = path[x] + 1;
            q.push(x-1);
        }
        if(check[x*2] == 0 && x*2 >= 0 && x*2 < 100001)
        {
            check[x*2] = 1;
            path[x*2] = path[x] + 1;
            q.push(x*2);
        }
    }
}

int main()
{
    cin >> n >> m;
    bfs(n);
    cout << path[m] << '\n';
}