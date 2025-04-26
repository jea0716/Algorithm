#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct ball
{
    int x;
    char dir;
};

int L, N, T, answer;
int ballX;
char ballDir;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> N >> T;
    vector<int> area(L + 1, 0);
    vector<ball> balls;

    for (int i = 0; i < N; i++)
    {
        cin >> ballX >> ballDir;
        balls.push_back({ballX, ballDir});
    }

    for (int i = 0; i < T; i++)
    {
        area.assign(L + 1, 0);
        for (int i = 0; i < N; i++)
        {
            if (balls[i].dir == 'R')
            {
                balls[i].x++;
                if (balls[i].x == L)
                {
                    balls[i].dir = 'L';
                }
            }
            else
            {
                balls[i].x--;
                if (balls[i].x == 0)
                {
                    balls[i].dir = 'R';
                }
            }

            area[balls[i].x]++;
        }

        for (int i = 0; i <= L; i++)
        {
            if (area[i] > 1)
            {
                answer++;
            }
        }
    }

    cout << answer << endl;

    return 0;
}