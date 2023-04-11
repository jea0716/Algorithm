#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int bfs(int start, int answer)
{
    queue <long> q;
    queue <long> w;
    q.push(start);
    w.push(1);
    int cnt = 1;
    while(!q.empty())
    {
        long x = q.front();
        long y = w.front();
        if(x == answer) return y;
        q.pop();
        w.pop();
        if(x * 2 <= answer)
        {
            q.push(x * 2);
            w.push(y+1);
        }
        if(x * 10 + 1 <= answer)
        {
            q.push(x * 10 + 1);
            w.push(y+1);
        }
    }
    return -1;
}

int main()
{
    int n, m; cin >> n >> m;
    int cnt = bfs(n, m);
    cout << cnt << endl;
}