#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct node {
    int n;
    string route;
};

int visited[10000];

int L(int n) {
    int a, b, c, d;
    d = n % 10;
    n /= 10;
    c = n % 10;
    n /= 10;
    b = n % 10;
    n /= 10;
    a = n % 10;

    return b * 1000 + c * 100 + d * 10 + a;
}

int R(int n) {
    int a, b, c, d;
    d = n % 10;
    n /= 10;
    c = n % 10;
    n /= 10;
    b = n % 10;
    n /= 10;
    a = n % 10;

    return d * 1000 + a * 100 + b * 10 + c;
}

string BFS(int n, int m) {
    visited[n] = true;
    queue<node> q;
    q.push({n, ""});

    while(!q.empty()) {
        int n = q.front().n;
        string route = q.front().route;
        q.pop();

        if(n == m) {
            return route;
        }

        if(!visited[(n * 2) % 10000]) {
            q.push({ (n * 2) % 10000, route + 'D' });
            visited[(n * 2) % 10000] = true;
        }

        if(!visited[n == 0 ? 9999 : n - 1]) {
            q.push({ n == 0 ? 9999 : n - 1, route + 'S' });
            visited[n == 0 ? 9999 : n - 1] = true;
        }

        int ln = L(n);
        int rn = R(n);

        if(!visited[ln]) {
            q.push({ ln, route + 'L' });
            visited[ln] = true;
        }

        if(!visited[rn]) {
            q.push({ rn, route + 'R' });
            visited[rn] = true;
        }
    }

    return "";
}

string solve() {
    int n, m; cin >> n >> m;

    for(int i=0; i<10000; i++) visited[i] = false;

    return BFS(n, m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;

    for(int i=0; i<N; i++) cout <<  solve() << endl;;

    return 0;
}