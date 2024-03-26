#include <string>
#include <vector>
#include <queue>

using namespace std;

struct node {
    int n, cnt;  
};

vector<vector<int>> v(20001);
int visited[20001];

int check(int n) {
    int tmp = 0, cnt = 0;
    for(int i=1; i<=n; i++) {
        if(visited[i] > tmp) {
            tmp = visited[i];
            cnt = 1;
        }
        else if(visited[i] == tmp) cnt++;
    }
    return cnt;
}

void BFS() {
    queue <node> q;
    visited[1] = 1;
    for(int i=0; i<v[1].size(); i++) {
        q.push({ v[1][i], 1 });
        visited[v[1][i]] = 1;
    }
    
    while(!q.empty()) {
        int n = q.front().n;
        int cnt = q.front().cnt;
        q.pop();
        
        for(int i=0; i<v[n].size(); i++) {
            if(visited[v[n][i]] == 0) {
                visited[v[n][i]] = cnt + 1;
                q.push({ v[n][i], cnt + 1});
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i=0; i<edge.size(); i++) {
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    BFS();
    answer = check(n);
    
    return answer;
}