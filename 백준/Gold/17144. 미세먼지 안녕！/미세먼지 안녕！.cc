#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

struct aircon{
    int x, y;
};

int R, C, T;
int map[55][55], tmp_map[55][55];
aircon up, down;
bool x_true = false;

void m_move()
{
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            int amount = map[i][j] / 5;
            int cnt = 0;
            tmp_map[i][j] += map[i][j];
            if(map[i+1][j] != -1 && i < R) {tmp_map[i+1][j] += amount; cnt++;}
            if(map[i-1][j] != -1 && i > 1) {tmp_map[i-1][j] += amount; cnt++;}
            if(map[i][j+1] != -1 && j < C) {tmp_map[i][j+1] += amount; cnt++;}
            if(map[i][j-1] != -1 && j > 1) {tmp_map[i][j-1] += amount; cnt++;}
            tmp_map[i][j] -= (amount * cnt);
        }
    }

    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            map[i][j] = tmp_map[i][j];
            tmp_map[i][j] = 0;
        }
    }
}

void a_on()
{
    map[up.x-1][1] = 0;
    map[down.x+1][1] = 0;
    for(int i=up.x-1; i>=1; i--) map[i][1] = map[i-1][1];
    for(int i=1; i<=C; i++) map[1][i] = map[1][i+1];
    for(int i=1; i<up.x; i++) map[i][C] = map[i+1][C];
    for(int i=C; i>2; i--) map[up.x][i] = map[up.x][i-1];

    for(int i=down.x+1; i<=R; i++) map[i][1] = map[i+1][1];
    for(int i=1; i<=C; i++) map[R][i] = map[R][i+1];
    for(int i=R; i>down.x; i--) map[i][C] = map[i-1][C];
    for(int i=C; i>2; i--) map[down.x][i] = map[down.x][i-1];

    map[up.x][2] = 0;
    map[down.x][2] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> R >> C >>T;

    int tmp;
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            cin >> tmp;
            map[i][j] = tmp;
            if(tmp == -1 && x_true == false)
            {
                up.x = i; up.y = j;
                x_true = true;
            }
            else if(tmp == -1 && x_true == true)
            {
                down.x = i; down.y = j;
            }
        }
    }

    for(int i=0; i<T; i++)
    {
        m_move();
        a_on();
    }
    int answer = 0;
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++) answer += map[i][j];
    }
    cout << answer + 2 << endl;
}