#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int visited[102][102];
int map[102][102];
int N, M, K, answer, tmp;
int col[4] = {-1, 0, 1, 0};
int row[4] = {0, -1, 0, 1};

void solve(int n, int m) {
    visited[n][m] = 1;
    tmp++;
    if(answer < tmp) answer = tmp;

    for(int i=0; i<4; i++) {
        if(n+col[i] >= 0 && n+col[i] < N && m+row[i] >= 0 && m+row[i] < M) {
            if(map[n+col[i]][m+row[i]] == 0 && visited[n+col[i]][m+row[i]] == 0) {
                solve(n+col[i], m+row[i]);
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M >> K;

    int start_X, start_Y, end_X, end_Y;
    vector <int> v;

    for(int k=0; k<K; k++) {
        cin >> start_X >> start_Y >> end_X >> end_Y;
        for(int i=start_Y; i<end_Y; i++) {
            for(int j=start_X; j<end_X; j++) map[i][j] = 1;
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(map[i][j] == 0 && visited[i][j] == 0) {
                answer = tmp = 0;
                solve(i, j);
                v.push_back(answer);
            }
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for(int i=0; i<v.size(); i++) cout << v[i] << " ";
    cout << "\n"; 

    return 0;
}