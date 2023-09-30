#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int map[301][301];
int visited[301][301];
int N, answer;

int col[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int row[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void bfs(int n, int m, int x, int y, int cnt) {
    if(n == x && m == y) {
        answer = cnt;
        return;
    }

    queue <tuple<int, int, int> > q;
    q.push(make_tuple(n, m, cnt));
    visited[n][m] = 1;

    while(!q.empty()) {
        int a = get<0>(q.front());
        int b = get<1>(q.front());
        int z = get<2>(q.front());
        if(a == x && b == y) {
            answer = z;
            return;
        }
        q.pop();
        for(int i=0; i<8; i++) {
            if(a+col[i] >= 0 && a+col[i] < N && b+row[i] >= 0 && b+row[i] < N) {
                if(visited[a+col[i]][b+row[i]] == 0) {
                    q.push(make_tuple(a+col[i], b+row[i], z+1));
                    visited[a+col[i]][b+row[i]] = 1;
                }
            } 
        }
    }

    return;
}

void reset(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) visited[i][j] = 0;
    }

    return;
}

void solve(int n) {
    int from_x, from_y, to_x, to_y;
    cin >> from_x >> from_y >> to_x >> to_y;

    bfs(from_x, from_y, to_x, to_y, 0);

    return;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num; cin >> num;

    for(int k=0; k<num; k++) {
        cin >> N;
        answer = 0;
        reset(N);
        solve(N);
        cout << answer << "\n";
    }

    return 0;
}