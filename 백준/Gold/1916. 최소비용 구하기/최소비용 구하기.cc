#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 999999999

vector <pair <int, int> > V[1001];
int dist[1001];

void dijkstra(int start)
{
    int cost, cur;
    int ncost, next;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    pq.push(make_pair(0, start));
    dist[start] = 0;

    while(!pq.empty())
    {
        cost = -pq.top().first;
        cur = pq.top().second;
        pq.pop();

        if(dist[cur] < cost) continue;

        for(int i=0; i<V[cur].size(); i++)
        {
            next = V[cur][i].first;
            ncost = V[cur][i].second;
            if(dist[next] > cost + ncost)
            {
                dist[next] = cost + ncost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;

    for(int i=1; i<=n; i++) dist[i] = INF;

    int start, end, cost;
    for(int i=0; i<m; i++)
    {
        cin >> start >> end >> cost;
        V[start].push_back(make_pair(end, cost));
    }

    int s_point, e_point; cin >> s_point >> e_point;
    dijkstra(s_point);

    cout << dist[e_point] << "\n";

    return 0;
}