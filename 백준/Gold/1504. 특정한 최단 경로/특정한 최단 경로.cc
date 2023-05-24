#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 999999999

int N, E;
int F_P, S_P;
int dist[1000];
vector <pair<int, int> > V[1000];

int dijkstra(int start, int end)
{
    int cost, cur, ncost, next;
    priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
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
            ncost = V[cur][i].first;
            next = V[cur][i].second;

            if(dist[next] > cost + ncost)
            {
                dist[next] = cost + ncost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }

    return dist[end];
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> E;
    int start, end, cost;
    for(int i=0; i<E; i++)
    {
        cin >> start >> end >> cost;
        V[start].push_back(make_pair(cost, end));
        V[end].push_back(make_pair(cost, start));
    }

    cin >> F_P >> S_P;

    int answer = 0, answer1 = 0, answer2 = 0, tmp;
    bool root1 = true, root2 = true;

    for(int i=0; i<=N; i++) dist[i] = INF;
    tmp = dijkstra(1, F_P);
    if(tmp == INF) root1 = false;
    answer1 += tmp;
    for(int i=0; i<=N; i++) dist[i] = INF;
    tmp = dijkstra(F_P, S_P);
    if(tmp == INF) root1 = false;
    answer1 += tmp;
    for(int i=0; i<=N; i++) dist[i] = INF;
    tmp = dijkstra(S_P, N);
    if(tmp == INF) root1 = false;
    answer1 += tmp;

    for(int i=0; i<=N; i++) dist[i] = INF;
    tmp = dijkstra(1, S_P);
    if(tmp == INF) root2 = false;
    answer2 += tmp;
    for(int i=0; i<=N; i++) dist[i] = INF;
    tmp = dijkstra(S_P, F_P);
    if(tmp == INF) root2 = false;
    answer2 += tmp;
    for(int i=0; i<=N; i++) dist[i] = INF;
    tmp = dijkstra(F_P, N);
    if(tmp == INF) root2 = false;
    answer2 += tmp;

    if(root1 == true && root2 == true)
    {
        answer = min(answer1, answer2);
    }
    else if(root1 == false) answer = answer2;
    else if(root2 == false) answer = answer1;
    if(root1 == false && root2 == false) answer = -1;

    cout << answer << "\n";
    
    return 0;
}