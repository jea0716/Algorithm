#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int N, Count;
};

int F, S, G, U, D;
char message[] = "use the stairs";
int map[1000001];
int visited[1000001];

void BFS(int n) {
    queue <node> q;
    q.push({ n, 0 });
    map[n] = 0;
    visited[n] = 1;

    while(!q.empty()) {
        int n = q.front().N;
        int count = q.front().Count;
        q.pop();

        if(n + U <= F && map[n + U] >= count + 1 && visited[n + U] == 0) {
            visited[n + U] = 1;
            map[n + U] = count + 1;
            q.push({ n + U, count + 1 });
        }
        if(n - D >= 1 && map[n - D] >= count + 1 && visited[n - D] == 0) {
            visited[n - D] = 1;
            map[n - D] = count + 1;
            q.push({ n - D, count + 1 });
        }
    }
}

int main() {
    cin >> F >> S >> G >> U >> D;

    for(int i=1; i<=F; i++) map[i] = 9999999;

    BFS(S);

    if(map[G] == 9999999) cout << message << "\n";
    else cout << map[G] << "\n";

    return 0;
}