#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int X, Count;
};

int to, from;
int visited[100001];

void BFS(int n) {
    queue <node> q;
    q.push({ n, 0 });
    visited[n] = 1;

    while(!q.empty()) {
        int n = q.front().X;
        int count = q.front().Count;
        q.pop();

        if(n + 1 <= 100000 && visited[n + 1] > count + 1) {
            visited[n + 1] = count + 1;
            q.push({ n + 1, count + 1 });
        }
        if(n - 1 >= 0 && visited[n - 1] > count + 1) {
            visited[n - 1] = count + 1;
            q.push({ n - 1, count + 1});
        }
        if(n * 2 <= 100000 && visited[n * 2] > count + 1) {
            visited[n * 2] = count + 1;
            q.push({ n * 2, count + 1 });
        }
    }
}

int main() {
    cin >> to >> from;

    for(int i=0; i<=100000; i++) visited[i] = 9999999;

    BFS(to);

    if(to == from) cout << 0 << endl;
    else cout << visited[from] << "\n";
}