#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 999999999

int n, k;
int visited[222222];


void bfs(int n)
{
    deque <int> q;
    q.push_back(n);
    visited[n] = 0;

    while(!q.empty())
    {
        int x = q.front();
        q.pop_front();
        if(x == k) return;
        if(x * 2 <= 200000 && visited[x] < visited[x * 2])
        {
            visited[x * 2] = visited[x];
            q.push_front(x * 2);
        }
        if(x >= 0 && visited[x] + 1 < visited[x - 1])
        {
            visited[x - 1] = visited[x] + 1;
            q.push_back(x - 1);
        }
        if(x < 100001 && visited[x] + 1 < visited[x + 1])
        {
            visited[x + 1] = visited[x] + 1;
            q.push_back(x + 1);
        }
    }
}

int main()
{
    cin >> n >> k;
    for(int i=0; i<=100000; i++) visited[i] = INF;

    bfs(n);

    cout << visited[k] << endl;

    return 0;
}