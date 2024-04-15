#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, to, from, answer=100;
vector <int> v(101, 0);
bool visited[101];

struct node {
    int location, cnt;
};

void BFS() {
    queue <node> q;
    q.push({ 1, 0 });
    visited[1] = true;

    while(!q.empty()) {
        int location = q.front().location;
        int cnt = q.front().cnt;
        q.pop();

        if(location == 100) {
            answer = answer < cnt ? answer : cnt;
            return;
        }

        for(int i=1; i<=6; i++) {
            if(location + i <= 100 && v[location + i] != 0 && (!visited[v[location + i]] || !visited[location + i])) {
                q.push({ v[location + i], cnt + 1 });
                visited[v[location + i]] = true;
                visited[location + i] = true;
            }

            else {
                if(location + i <= 100 && !visited[location + i]) {
                    q.push({ location + i, cnt + 1 });
                    visited[location + i] = true;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;

    for(int i=0; i<N; i++) {
        cin >> to >> from;
        v[to] = from;
    }

    for(int i=0; i<M; i++) {
        cin >> to >> from;
        v[to] = from;
    }

    BFS();

    cout << answer << '\n';

    return 0;
}