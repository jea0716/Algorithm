#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int n, cnt;
};
const int INF = 987654321;

int N, K, answer = INF, answer_num;
vector<int> visited(200001, INF);

void BFS() {
    queue <node> q;
    q.push({ N, 0 });
    visited[N] = 0;

    while(!q.empty()) {
        int n = q.front().n;
        int cnt = q.front().cnt;
        q.pop();

        if(n == K) {
            if(answer == cnt) answer_num++;
            else {
                answer = cnt;
                answer_num = 1;
            }
        }

        if(n + 1 <= K && cnt + 1 <= visited[n + 1] ) {
            q.push({ n + 1, cnt + 1 });
            visited[n + 1] = cnt + 1;
        }
        if(n - 1 >= 0 && cnt + 1 <= visited[n - 1] ) {
            q.push({ n - 1, cnt + 1 });
            visited[n - 1] = cnt + 1;
        }
        if(n * 2 <= 2 * K && cnt + 1 <= visited[n * 2] ) {
            q.push({ n * 2, cnt + 1 });
            visited[n * 2] = cnt + 1;
        }
    }
}

int main() {
    cin >> N >> K;

    BFS();

    cout << answer << '\n' << answer_num << '\n';

    return 0;
}