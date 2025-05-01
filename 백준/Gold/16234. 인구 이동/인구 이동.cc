#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct node
{
    int x, y;
};

int N, L, R, ANSWER;
int area[51][51];
bool visited[51][51];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool check()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i + 1 < N && abs(area[i][j] - area[i + 1][j]) >= L && abs(area[i][j] - area[i + 1][j]) <= R)
                return true;
            if (i - 1 >= 0 && abs(area[i][j] - area[i - 1][j]) >= L && abs(area[i][j] - area[i - 1][j]) <= R)
                return true;
            if (j + 1 < N && abs(area[i][j] - area[i][j + 1]) >= L && abs(area[i][j] - area[i][j + 1]) <= R)
                return true;
            if (j - 1 >= 0 && abs(area[i][j] - area[i][j - 1]) >= L && abs(area[i][j] - area[i][j - 1]) <= R)
                return true;
        }
    }

    return false;
}

void BFS(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    int sum = area[x][y], cnt = 1;
    vector<node> areas(1, {x, y});

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || nx >= N)
                continue;
            if (ny < 0 || ny >= N)
                continue;
            if (visited[nx][ny])
                continue;
            if (abs(area[nx][ny] - area[cx][cy]) < L)
                continue;
            if (abs(area[nx][ny] - area[cx][cy]) > R)
                continue;

            sum += area[nx][ny];
            cnt++;
            areas.push_back({nx, ny});

            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }

    for (int i = 0; i < areas.size(); i++)
    {
        area[areas[i].x][areas[i].y] = sum / areas.size();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L >> R;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> area[i][j];
        }
    }

    while (check())
    {
        ANSWER++;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                visited[i][j] = false;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visited[i][j])
                {
                    BFS(i, j);
                }
            }
        }
    }

    cout << ANSWER << '\n';

    return 0;
}