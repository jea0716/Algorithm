#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 99999999

vector <pair <int, int> > v[20100];

void solve(int num, int dist[])
{
    int cost, cur;
    int ncost, next;
    int i;

    priority_queue<pair<int, int> > pq;

    dist[num] = 0;
    pq.push(make_pair(0, num));
    while(!pq.empty())
    {
        cost = -pq.top().first;
        cur = pq.top().second;
        pq.pop();
        i = 0;

        while(i < v[cur].size())
        {
            next = v[cur][i].first;
            ncost = v[cur][i].second;
            if(dist[next] > cost + ncost)
            {
                dist[next] = cost + ncost;
                pq.push(make_pair(-dist[next], next));
            }
            i++;
        }
    }
}

int main()
{
    int n, m; cin >> n >> m;

    int dist[n+1];
    for(int i=1; i<=n; i++) dist[i] = INF;

    int num; cin >> num;

    int start, end, cost;
    for(int i=0; i<m; i++)
    {
        cin >> start >> end >> cost;
        v[start].push_back(make_pair(end, cost));
    }

    solve(num, dist);

    for(int i=1; i<=n; i++){
        if(dist[i] == INF) cout << "INF" << "\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}