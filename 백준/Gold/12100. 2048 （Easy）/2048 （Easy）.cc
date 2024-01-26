#include <iostream>
#include <queue>

using namespace std;

int N;
int map[21][21];
int answer = 0;

void UP() {
    queue <int> q;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(map[i][j] != 0) q.push(map[i][j]);
            map[i][j] = 0;
        }

        int idx = 0;
        while(!q.empty()) {
            int value = q.front();
            q.pop();

            if(map[i][idx] == 0)  map[i][idx] = value;
            else if(map[i][idx] == value) map[i][idx++] *= 2;
            else map[i][++idx] = value;
        }
    }
}

void DOWN() {
    queue <int> q;
    for(int i=0; i<N; i++) {
        for(int j=N-1; j>=0; j--) {
            if(map[i][j] != 0) q.push(map[i][j]);
            map[i][j] = 0;
        }

        int idx = N-1;
        while(!q.empty()) {
            int value = q.front();
            q.pop();

            if(map[i][idx] == 0)  map[i][idx] = value;
            else if(map[i][idx] == value) map[i][idx--] *= 2;
            else map[i][--idx] = value;
        }
    }
}

void LEFT() {
    queue <int> q;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(map[j][i] != 0) q.push(map[j][i]);
            map[j][i] = 0;
        }

        int idx = 0;
        while(!q.empty()) {
            int value = q.front();
            q.pop();

            if(map[idx][i] == 0)  map[idx][i] = value;
            else if(map[idx][i] == value) map[idx++][i] *= 2;
            else map[++idx][i] = value;
        }
    }
}

void RIGHT() {
    queue <int> q;
    for(int i=0; i<N; i++) {
        for(int j=N-1; j>=0; j--) {
            if(map[j][i] != 0) q.push(map[j][i]);
            map[j][i] = 0;
        }

        int idx = N-1;
        while(!q.empty()) {
            int value = q.front();
            q.pop();

            if(map[idx][i] == 0)  map[idx][i] = value;
            else if(map[idx][i] == value) map[idx--][i] *= 2;
            else map[--idx][i] = value;
        }
    }
}

void DFS(int count) {
    if(count == 5) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(map[i][j] > answer) answer = map[i][j];
            }
        }
        return;
    }

    int copy_map[N][N];
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) copy_map[i][j] = map[i][j];
    }

    UP();
    DFS(count+1);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) map[i][j] = copy_map[i][j];
    }

    DOWN();
    DFS(count+1);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) map[i][j] = copy_map[i][j];
    }

    LEFT();
    DFS(count+1);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) map[i][j] = copy_map[i][j];
    }

    RIGHT();
    DFS(count+1);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) map[i][j] = copy_map[i][j];
    }

}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);

    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) cin >> map[i][j];
    }

    DFS(0);
    cout << answer << endl;
    return 0;
}