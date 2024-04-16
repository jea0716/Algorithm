#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
    int n, cnt;
};

int N, K, answer;
int visited[200001];

void BFS() {
    queue <node> q;
    q.push({ N, 0 });
    visited[N] = 1;

    while(!q.empty()) {
        int n = q.front().n;
        int cnt = q.front().cnt;
        q.pop();

        if(n == K) {
            answer = cnt;
            return;
        }

        if(n * 2 <= 2 * K && !visited[n * 2]) {
            q.push({ n * 2, cnt });
            visited[n * 2] = 1;
        }

        if(n - 1 >= 0 && !visited[n - 1]) {
            q.push({ n - 1, cnt + 1 });
            visited[n - 1] = 1;
        }

        if(n + 1 <= 2 * K && !visited[n + 1]) {
            q.push({ n + 1, cnt + 1 });
            visited[n + 1] = 1;
        }
    }
}

int main() {
    cin >> N >> K;

    BFS();

    cout << answer << "\n";

    return 0;
}