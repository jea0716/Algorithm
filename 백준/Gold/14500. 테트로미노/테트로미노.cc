#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int map[501][501];
int visited[501][501];
int ans;

void solve(int x, int y, int cnt, int sum)
{
    visited[x][y] = 1;

    if(cnt == 4 && ans < sum) ans = sum;

    if(x - 1 >= 0 && visited[x-1][y] == 0 && cnt < 4)
    {
        visited[x-1][y] = 1;
        solve(x-1, y, cnt+1, sum+map[x-1][y]);
        visited[x-1][y] = 0;
    }
    if(x + 1 < N && visited[x+1][y] == 0 && cnt < 4) 
    {
        visited[x+1][y] = 1;
        solve(x+1, y, cnt+1, sum+map[x+1][y]);
        visited[x+1][y] = 0;
    }
    if(y - 1 >= 0 && visited[x][y-1] == 0 && cnt < 4)
    {
        visited[x][y-1] = 1;
        solve(x, y-1, cnt+1, sum+map[x][y-1]);
        visited[x][y-1] = 0;
    }
    if(y + 1 < M && visited[x][y+1] == 0 && cnt < 4) 
    {
        visited[x][y+1] = 1;
        solve(x, y+1, cnt+1, sum+map[x][y+1]);
        visited[x][y+1] = 0;
    }
    if(cnt==1 && x-1>=0 && x+1<N && y-1>=0) ans = max(ans, map[x][y]+map[x-1][y]+map[x+1][y]+map[x][y-1]);
    if(cnt==1 && x-1>=0 && x+1<N && y+1<M) ans = max(ans, map[x][y]+map[x-1][y]+map[x+1][y]+map[x][y+1]);
    if(cnt==1 && x-1>=0 && y-1>=0 && y+1<M) ans = max(ans, map[x][y]+map[x-1][y]+map[x][y-1]+map[x][y+1]);
    if(cnt==1 && x+1<N && y-1>=0 && y+1<M) ans = max(ans, map[x][y]+map[x+1][y]+map[x][y-1]+map[x][y+1]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++) cin >> map[i][j];
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            visited[i][j] = 1;
            solve(i, j, 1, map[i][j]);
            visited[i][j] = 0;
        }
    }

    cout << ans << "\n";

    return 0;
}