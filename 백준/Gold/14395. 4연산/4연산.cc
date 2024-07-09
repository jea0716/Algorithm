#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>

using namespace std;



struct node {
    long long n;
    string s;
};

long long S, T;
set<long long> visited;

char dr[] = { '*', '+', '-', '/' };

long long cal(long long n, int i) {
    if(i == 0) return n * n;
    else if(i == 1) return n + n;
    else if(i == 2) return n - n;
    else if(i == 3) return n / n;

    return 0;
}

string BFS() {
    queue <node> q;
    q.push({ S, "" });
    visited.insert(S);

    while(!q.empty()) {
        long long n = q.front().n;
        string s = q.front().s;
        q.pop();

        if(n == T) return s;

        for(int i=0; i<4; i++) {
            long long nx = cal(n, i);
            if(nx < 1) continue;
            if(visited.find(nx) != visited.end()) continue;
            visited.insert(nx);
            q.push({ nx, s + dr[i] });
        }
    }

    return "-1";
}

int main() {
    cin >> S >> T;

    if(S == T) cout << 0 << '\n';
    else cout << BFS() << '\n';

    return 0;
}