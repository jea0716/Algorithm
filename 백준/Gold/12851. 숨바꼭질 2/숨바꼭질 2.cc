#include <iostream>
#include <queue>

using namespace std;

int N, M; 
int min_sec = 987654321;
int min_cnt;
int visited[200001];

void solve(int n, int sec)
{
    queue <pair<int, int> > q;
    q.push(make_pair(n, 0));
    visited[n] = 1;

    while(!q.empty())
    {
        int tmp = q.front().first;
        int tmp_sec = q.front().second;
        q.pop();

        visited[tmp] = 1;

        if(tmp == M)
        {
            if(min_sec > tmp_sec)
            {
                min_sec = tmp_sec;
                min_cnt = 1;
            }
            else if(min_sec == tmp_sec) min_cnt++;
        }
        
        if(tmp+1 <= M && visited[tmp + 1] == 0)
        {
            q.push(make_pair(tmp+1, tmp_sec+1));
        }

        if(tmp-1 >= 0 && visited[tmp - 1] == 0)
        {
            q.push(make_pair(tmp-1, tmp_sec+1));
        }

        if(tmp*2 <= M*2 && visited[tmp * 2] == 0)
        {
            q.push(make_pair(tmp*2, tmp_sec+1));
        }
    }
}

int main()
{
    cin >> N >> M;

    solve(N, 0);

    cout << min_sec << "\n" << min_cnt << endl;
}