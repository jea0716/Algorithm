#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 999999999

int N, M, X;
int s_dist[1001], e_dist[1001];

vector <pair<int, int> > V[1001];
vector <pair<int, int> > V2[1001];

void dijkstra(int start)
{
    int cost, cur;
    int ncost, next;
    priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
    pq.push(make_pair(0, start));
    s_dist[start] = 0;

    while(!pq.empty())
    {
        cost = -pq.top().first;
        cur = pq.top().second;
        pq.pop();

        if(s_dist[cur] < cost) continue;

        for(int i=0; i<V[cur].size(); i++)
        {
            ncost = V[cur][i].first;
            next = V[cur][i].second;

            if(s_dist[next] > cost + ncost)
            {
                s_dist[next] = cost + ncost;
                pq.push(make_pair(-s_dist[next], next));
            }
        }
    }
}

void dijkstra2(int start)
{
    int cost, cur;
    int ncost, next;
    priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
    pq.push(make_pair(0, start));
    e_dist[start] = 0;

    while(!pq.empty())
    {
        cost = -pq.top().first;
        cur = pq.top().second;
        pq.pop();

        if(e_dist[cur] < cost) continue;

        for(int i=0; i<V2[cur].size(); i++)
        {
            ncost = V2[cur][i].first;
            next = V2[cur][i].second;

            if(e_dist[next] > cost + ncost)
            {
                e_dist[next] = cost + ncost;
                pq.push(make_pair(-e_dist[next], next));
            }
        }
    }

    return ;
}

int main()
{
    cin >> N >> M >> X;

    for(int i=0; i<=N; i++)
    {
        s_dist[i] = INF;
        e_dist[i] = INF;
    }

    int start, end, cost;
    for(int i=0; i<M; i++)
    {
        cin >> start >> end >> cost;
        V[start].push_back(make_pair(cost, end));
        V2[end].push_back(make_pair(cost, start));
    }

    dijkstra(X);
    dijkstra2(X);

    int answer = 0;
    for(int i=1; i<=N; i++) answer = max(answer, s_dist[i]+e_dist[i]);

    cout << answer << "\n";

    return 0;
}