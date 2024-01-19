#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int X, Y;
};

int N;
node To, From;
node store[101];
int visited[101];

void clear() {
    for(int i=0; i<=100; i++) visited[i] = 0;
}

void checkVisited(node n) {
    for(int i=0; i<N; i++) {
        if(n.X == store[i].X && n.Y == store[i].Y) visited[i] = 1;
    }
}

bool BFS() {
    queue <node> q;
    q.push(To);
    checkVisited(To);

    while(!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        if(abs(From.X - x) + abs(From.Y - y) <= 1000) return true;

        for(int i=0; i<N; i++) {
            if(visited[i] == 1) continue;
            int distance_x = abs(store[i].X - x);
            int distance_y = abs(store[i].Y - y);

            if(distance_x + distance_y > 1000) continue;
            q.push(store[i]);
            visited[i] = 1;
        }
    }

    return false;
}

int main() {
    int T; cin >> T;

    for(int t=0; t<T; t++) {
        clear();
        cin >> N;
        cin >> To.X >> To.Y;
        for(int i=0; i<N; i++) {
            cin >> store[i].X >> store[i].Y;
        }
        cin >> From.X >> From.Y;

        if(BFS()) cout << "happy\n";
        else cout << "sad\n";
    }

    return 0;
}