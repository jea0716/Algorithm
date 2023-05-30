#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct props{
    int x;
    int y;
    int sec;
};

int N;
int map[20][20], visited[20][20];
int baby_shark = 2, eat, ans, tmp_sec, x, y, tmp_x, tmp_y;

vector <pair<int, int> > area;

void solve(int start_x, int start_y)
{
    queue <props> q;
    props start;
    start.x = start_x;
    start.y = start_y;
    start.sec = 0;
    q.push(start);
    visited[start_x][start_y] = 1;

    while(!q.empty())
    {
        int a = q.front().x;
        int b = q.front().y;
        int c = q.front().sec;
        q.pop();

        if(map[a][b] > 0 && map[a][b] < baby_shark && tmp_sec >= c && map[a][b] != 9)
        {
            if(tmp_sec > c)
            {
                tmp_sec = c; x = a; y = b;
                area.erase(area.begin(), area.end());
                area.push_back(make_pair(x, y));
            }
            else
            {
                area.push_back(make_pair(a, b));
            }
        }

        props tmp;

        if(b - 1 >= 0 && visited[a][b-1] == 0 && map[a][b-1] <= baby_shark)
        {
            visited[a][b-1] = 1;
            tmp.x = a;
            tmp.y = b - 1;
            tmp.sec = c + 1;
            q.push(tmp);
        }
        if(a - 1 >= 0 && visited[a-1][b] == 0 && map[a-1][b] <= baby_shark)
        {
            visited[a-1][b] = 1;
            tmp.x = a - 1;
            tmp.y = b;
            tmp.sec = c + 1;
            q.push(tmp);
        }
        if(a + 1 < N && visited[a+1][b] == 0 && map[a+1][b] <= baby_shark)
        {
            visited[a+1][b] = 1;
            tmp.x = a + 1;
            tmp.y = b;
            tmp.sec = c + 1;
            q.push(tmp);
        }
        if(b + 1 < N && visited[a][b+1] == 0 && map[a][b+1] <= baby_shark)
        {
            visited[a][b+1] = 1;
            tmp.x = a;
            tmp.y = b + 1;
            tmp.sec = c + 1;
            q.push(tmp);
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

    int cnt;

    do
    {
        cnt = 0; tmp_sec = 999999999;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(map[i][j] == 9)
                {
                    x = i; y = j;
                }
                else if(map[i][j] != 0 && map[i][j] < baby_shark) cnt++;
                visited[i][j] = 0;
            }
        }
        
        
        tmp_x = x, tmp_y = y;
        solve(x, y);
        for(int i=0; i<area.size(); i++)
        {
            if(i == 0)
            {
                x = area[0].first; y = area[0].second;
            }
            else
            {
                if(area[i].first < x)
                {
                    x = area[i].first;
                    y = area[i].second;
                }
                if(area[i].first == x && area[i].second < y)
                {
                    x = area[i].first;
                    y = area[i].second;
                }
            }
        }

        if(tmp_x != x || tmp_y != y)
        {
            map[tmp_x][tmp_y] = 0; map[x][y] = 9; eat++;
        }

        if(baby_shark == eat)
        {
            baby_shark++;
            eat = 0;
        }

        if(tmp_sec != 999999999) ans += tmp_sec;
    } while (!(tmp_x == x && tmp_y == y));

    cout << ans << endl;

    return 0;
}