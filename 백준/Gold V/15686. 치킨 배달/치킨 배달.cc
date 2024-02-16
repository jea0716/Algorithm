#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
    int X, Y;
};

int N, M;
int map[51][51];
int answer = 999999999;
int visited[15];
vector <node> home;
vector <node> chicken;

int check_distance(vector <int> n) {
    int sum_distance = 0;

    for(int i=0; i<home.size(); i++) {
        int distance = 99999;
        for(int j=0; j<n.size(); j++) {
            distance = min(distance, abs(chicken[n[j]].X - home[i].X) + abs(chicken[n[j]].Y - home[i].Y));
        }
        sum_distance += distance;
    }

    return sum_distance;
}

void DFS(int count, int n) {
    if(count == M) {
        vector <int> v;
        for(int i=0; i<15; i++) {
            if(visited[i] == 1) v.push_back(i);
        }
        int sum = check_distance(v);

        answer = answer < sum ? answer : sum;
    }

    for(int i=0; i<chicken.size(); i++) {
        if(visited[i] == 1 || n > i)  continue;
        visited[i] = 1;
        DFS(count + 1, i);
        visited[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) home.push_back({ i, j });
            if(map[i][j] == 2) chicken.push_back({ i, j });
        }
    }

    DFS(0, 0);

    cout << answer << "\n";

    return 0;
}