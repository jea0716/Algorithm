#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>

using namespace std;

const int INF = 1e9;
int N, cnt;
int arr[126][126], dist[126][126];
bool check = true;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void solve() {
    cnt++;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) dist[i][j] = INF;
    }

    dist[0][0] = arr[0][0];
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({ -arr[0][0], { 0, 0 } });

    while(!pq.empty()) {
        int d = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N) continue;
            if(ny < 0 || ny >= N) continue;

            if(d + arr[nx][ny] >= dist[nx][ny]) continue;

            pq.push({ -(d + arr[nx][ny]), { nx, ny } });
            dist[nx][ny] = d + arr[nx][ny];
        }
    }
    
    cout << "Problem " << cnt << ": " << dist[N-1][N-1] << endl;
}

void Input() {
    cin >> N;

    if(N == 0) {
        check = false;
        return ;
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) cin >> arr[i][j];
    }

    solve();

    return ;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    while(check) Input();

    return 0;
}