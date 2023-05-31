#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int map[16][16];
int dp[16][16];

struct shape{
    int x, y;
    bool a, b, c;
};

void solve(int start_x, int start_y, bool a, bool b, bool c)
{
    queue <shape> q;
    shape start = {start_x, start_y, a, b, c};
    q.push(start);

    while(!q.empty())
    {
        int xx = q.front().x;
        int yy = q.front().y;
        bool aa = q.front().a;
        bool bb = q.front().b;
        bool cc = q.front().c;
        q.pop();

        if(xx + 1 < N && map[xx+1][yy] == 0 && cc == true)
        {
            dp[xx+1][yy] += 1;
            shape tmp = {xx+1, yy, false, true, true};
            q.push(tmp);
        }

        if(yy + 1 < N && map[xx][yy+1] == 0 && aa == true)
        {
            dp[xx][yy+1] += 1;
            shape tmp = {xx, yy+1, true, true, false};
            q.push(tmp);
        }

        if(xx + 1 < N && yy + 1 < N && bb == true)
        {
            if(map[xx+1][yy] == 0 && map[xx+1][yy+1] == 0 && map[xx][yy+1] == 0)
            {
                dp[xx+1][yy+1] += 1;
                shape tmp = {xx+1, yy+1, true, true, true};
                q.push(tmp);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++) cin >> map[i][j];
    }

    solve(0, 1, true, true, false);
    cout << dp[N-1][N-1] << "\n";

    return 0;
}