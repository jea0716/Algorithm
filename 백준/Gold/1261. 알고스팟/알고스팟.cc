#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

#define INF 999999999

int N, M;
int map[101][101];
int dist[101][101];

void solve()
{
    deque <pair<int, int> > q;
    q.push_back(make_pair(1, 1));
    dist[1][1] = 0;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();

        if(x == N && y == M) return;
        if(x + 1 <= N && map[x+1][y] == 1)
        {
            if(dist[x][y] + 1 < dist[x+1][y])
            {
                dist[x+1][y] = dist[x][y] + 1;
                q.push_back(make_pair(x+1, y));
            }
        }
        if(x + 1 <= N && map[x+1][y] == 0)
        {
            if(dist[x][y] < dist[x+1][y])
            {
                dist[x+1][y] = dist[x][y];
                q.push_front(make_pair(x+1, y));
            }
        }
        if(x - 1 >= 1 && map[x-1][y] == 1)
        {
            if(dist[x][y] + 1 < dist[x-1][y])
            {
                dist[x-1][y] = dist[x][y] + 1;
                q.push_back(make_pair(x-1, y));
            }
        }
        if(x - 1 >= 1 && map[x-1][y] == 0)
        {
            if(dist[x][y] < dist[x-1][y])
            {
                dist[x-1][y] = dist[x][y];
                q.push_front(make_pair(x-1, y));
            }
        }
        if(y + 1 <= M && map[x][y+1] == 1)
        {
            if(dist[x][y] + 1 < dist[x][y+1])
            {
                dist[x][y+1] = dist[x][y] + 1;
                q.push_back(make_pair(x, y+1));
            }
        }
        if(y + 1 <= M && map[x][y+1] == 0)
        {
            if(dist[x][y] < dist[x][y+1])
            {
                dist[x][y+1] = dist[x][y];
                q.push_front(make_pair(x, y+1));
            }
        }
        if(y - 1 >= 1 && map[x][y-1] == 1)
        {
            if(dist[x][y] + 1 < dist[x][y-1])
            {
                dist[x][y-1] = dist[x][y] + 1;
                q.push_back(make_pair(x, y-1));
            }
        }
        if(y - 1 >= 1 && map[x][y-1] == 0)
        {
            if(dist[x][y] < dist[x][y-1])
            {
                dist[x][y-1] = dist[x][y];
                q.push_front(make_pair(x, y-1));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;

    string s;
    for(int i=1; i<=M; i++)
    {
        cin >> s;
        for(int j=0; j<N; j++)
        {
            int tmp = s[j] - '0';
            map[j+1][i] = tmp;
        }
    }

    for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=N; j++)
        {
            dist[j][i] = INF;
        }
    }

    solve();

    cout << dist[N][M] << "\n";

    return 0;
}