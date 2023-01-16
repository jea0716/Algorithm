#include <iostream>
#include <queue>

using namespace std;

int bridge[120], snake[120], path[120], check[120];

queue<int> q;

void bfs(int n)
{
    q.push(n);
    path[n] = 0;
    check[n] = 1;
    while(!q.empty())
    {
        int x = q.front();
        if(x == 100) break;
        q.pop();
        for(int i=1; i<=6; i++)
        {
            if(bridge[x + i] == 0 && snake[x + i] == 0 && check[x + i] == 0)
            {
                path[x + i] = path[x] + 1;
                check[x + i] = 1;
                q.push(x + i);
            }
            else if(bridge[x + i] != 0 && check[bridge[x + i]] == 0)
            {
                path[bridge[x + i]] = path[x] + 1;
                check[bridge[x + i]] = 1;
                q.push(bridge[x + i]);
            }
            else if(snake[x + i] != 0 && check[snake[x + i]] == 0)
            {
                path[snake[x + i]] = path[x] + 1;
                check[snake[x + i]] = 1;
                q.push(snake[x + i]);
            }
        }
    }
}

int main()
{
    int N, M; cin >> N >> M;
    int a, b;
    for(int i=0; i<N; i++)
    {
        cin >> a >> b;
        bridge[a] = b;
    }
    for(int i=0; i<M; i++)
    {
        cin >> a >> b;
        snake[a] = b;
    }
    bfs(1);


    cout << path[100] << endl;
}