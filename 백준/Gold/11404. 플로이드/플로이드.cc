#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 987654321

int N, M;

vector <pair<int,int> > V[101];
int dist[101];

void dijkstra(int start)
{
    int cost, cur, ncost, next;
    priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int, int> > > q;
    q.push(make_pair(0, start));
    dist[start] = 0;

    while(!q.empty())
    {
        cost = -q.top().first;
        cur = q.top().second;
        q.pop();

        if(dist[cur] < cost) continue;

        for(int i=0; i<V[cur].size(); i++)
        {
            ncost = V[cur][i].first;
            next = V[cur][i].second;

            if(dist[next] > ncost + cost)
            {
                dist[next] = ncost + cost;
                q.push(make_pair(-dist[next], next));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    int start, end, cost;
    for(int i=0; i<M; i++)
    {
        cin >> start >> end >> cost;
        V[start-1].push_back(make_pair(cost, end-1));
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            dist[j] = INF;
        }

        dijkstra(i);

        for(int j=0; j<N; j++)
        {
            if(dist[j] == INF) cout << 0 << " ";
            else cout << dist[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}