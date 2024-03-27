#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[201];

vector<vector<int>> v(201);

void BFS(int n) {
    queue <int> q;
    for(int i=0; i<v[n].size(); i++) {
        q.push(v[n][i]);
        visited[v[n][i]] = true;
    }
    
    while(!q.empty()) {
        int num = q.front();
        q.pop();
        
        for(int i=0; i<v[num].size(); i++) {
            if(!visited[v[num][i]]) {
                visited[v[num][i]] = true;
                q.push(v[num][i]);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<computers.size(); i++) {
        for(int j=0; j<computers[i].size(); j++) {
            if(computers[i][j] == 1) v[i].push_back(j);
        }
    }
    
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            BFS(i);
            answer++;
        }
    }
    
    return answer;
}