#include <iostream>

using namespace std;

int N;
int map[21][21];
int visited[21];
int red, blue;
int answer = 99999999;

int SUM(int n, bool check) {
    int sum = 0;
    for(int i=1; i<=N; i++) {
        if(check && visited[i]) sum += map[i][n];
        if(!check && !visited[i]) sum += map[i][n];
    }

    return sum;
}

void DFS(int n, int count) {
    if(count == N / 2) {
        red = 0, blue = 0;
        for(int i=1; i<=N; i++) {
            if(visited[i]) red += SUM(i, true);
            else blue += SUM(i, false);
        }

        answer = answer < abs(red - blue) ? answer : abs(red - blue);

        return;
    }

    for(int i=1; i<=N; i++){
        if(visited[i] || n >= i) continue;
        visited[i] = 1;
        DFS(i, count + 1);
        visited[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) cin >> map[i][j];
    }

    DFS(0, 0);

    cout << answer << "\n";

    return 0;
}