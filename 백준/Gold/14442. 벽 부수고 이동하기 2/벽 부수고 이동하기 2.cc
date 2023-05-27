#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

#define INF 999999999

struct props{
    int first;
    int second;
    int third;
};

int N, M, K;
int map[1001][1001];
int visited[11][1001][1001];

void bfs(int w, int start_x, int start_y)
{
    queue <props> q;
    props start;
    start.first = w;
    start.second = start_x;
    start.third = start_y;
    q.push(start);
    visited[w][start_x][start_y] = 1;

    while(!q.empty())
    {
        int z = q.front().first;
        int x = q.front().second;
        int y = q.front().third;
        q.pop();

        props tmp;

        if(x + 1 <= N && map[x+1][y] == 0)
        {   
            if(visited[z][x+1][y] > visited[z][x][y] + 1)
            {  
                visited[z][x+1][y] = visited[z][x][y] + 1;
                tmp.first = z;
                tmp.second = x + 1;
                tmp.third = y;
                q.push(tmp);
            }
        }
        if(x + 1 <= N && map[x+1][y] == 1 && z <= K && visited[z+1][x+1][y] == INF)
        {
            if(visited[z+1][x+1][y] >= visited[z][x][y] + 1)
            {
                visited[z+1][x+1][y] = visited[z][x][y] + 1;
                tmp.first = z + 1;
                tmp.second = x + 1;
                tmp.third = y;
                q.push(tmp);
            }
        }
        if(x - 1 >= 0 && map[x-1][y] == 0)
        {
            if(visited[z][x-1][y] > visited[z][x][y] + 1)
            {
                visited[z][x-1][y] = visited[z][x][y] + 1;
                tmp.first = z;
                tmp.second = x - 1;
                tmp.third = y;
                q.push(tmp);
            }
        }
        if(x - 1 >= 0 && map[x-1][y] == 1 && z <= K && visited[z+1][x-1][y] == INF)
        {
            if(visited[z+1][x-1][y] >= visited[z][x][y] + 1)
            {
                visited[z+1][x-1][y] = visited[z][x][y] + 1;
                tmp.first = z + 1;
                tmp.second = x - 1;
                tmp.third = y;
                q.push(tmp);
            }
        }
        if(y + 1 <= M && map[x][y+1] == 0)
        {
            if(visited[z][x][y+1] > visited[z][x][y] + 1)
            {
                visited[z][x][y+1] = visited[z][x][y] + 1;
                tmp.first = z;
                tmp.second = x;
                tmp.third = y + 1;
                q.push(tmp);
            }
        }
        if(y + 1 <= M && map[x][y+1] == 1 && z <= K && visited[z+1][x][y+1] == INF)
        {
            if(visited[z+1][x][y+1] >= visited[z][x][y] + 1)
            {
                visited[z+1][x][y+1] = visited[z][x][y] + 1;
                tmp.first = z + 1;
                tmp.second = x;
                tmp.third = y + 1;
                q.push(tmp);
            }
        }
        if(y - 1 >= 0 && map[x][y-1] == 0)
        {
            if(visited[z][x][y-1] > visited[z][x][y] + 1)
            {
                visited[z][x][y-1] = visited[z][x][y] + 1;
                tmp.first = z;
                tmp.second = x;
                tmp.third = y - 1;
                q.push(tmp);
            }
        }
        if(y - 1 >= 0 && map[x][y-1] == 1 && z <= K && visited[z+1][x][y-1] == INF)
        {
            if(visited[z+1][x][y-1] >= visited[z][x][y] + 1)
            {
                visited[z+1][x][y-1] = visited[z][x][y] + 1;
                tmp.first = z + 1;
                tmp.second = x;
                tmp.third = y - 1;
                q.push(tmp);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;

    string s;
    for(int i=0; i<N; i++)
    {
        cin >> s;
        for(int j=0; j<M; j++)
        {
            map[i][j] = s[j] - '0';
        }
    }

    for(int l=0; l<=K; l++)
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                visited[l][i][j] = INF;
            }
        }
    }

    bfs(0, 0, 0);

    int answer = -1;
    int min_num = INF;
    for(int i=0; i<=K; i++)
    {
        min_num = min(min_num, visited[i][N-1][M-1]);
    }
    if(min_num != INF) answer = min_num;
    cout << answer << "\n";

    return 0;
}