#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct node {
    int x, y, cnt;
};

node start, labber, e;
int answer;
bool visited[101][101];
bool check_L, check_E;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void visited_clear() {
    for(int i=0; i<101; i++) {
        for(int j=0; j<101; j++) visited[i][j] = false;
    }
}

void BFS(node n, vector<string> maps, node end_point) {
    visited_clear();
    queue <node> q;
    q.push(n);
    visited[n.x][n.y] = true;
    
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();
        
        if(x == end_point.x && y == end_point.y) {
            answer += cnt;
            if(maps[x][y] == 'L') check_L = true;
            if(maps[x][y] == 'E') check_E = true;
            return;
        }
        
        for(int i=0; i<4; i++){
            if(x + dx[i] < 0 || x + dx[i] >= maps.size()) continue;
            if(y + dy[i] < 0 || y + dy[i] >= maps[0].length()) continue;
            
            if(
                !visited[x + dx[i]][y + dy[i]] && 
                (
                    maps[x + dx[i]][y + dy[i]] == 'O' ||
                    maps[x + dx[i]][y + dy[i]] == 'L' ||
                    maps[x + dx[i]][y + dy[i]] == 'S' ||
                    maps[x + dx[i]][y + dy[i]] == 'E'
                )
            ) {
                q.push({ x + dx[i], y + dy[i], cnt + 1 });
                visited[x + dx[i]][y + dy[i]] = true;
            }
        }
    }
}

int solution(vector<string> maps) {
    for(int i=0; i<maps.size(); i++) {
        for(int j=0; j<maps[i].length(); j++) {
            if(maps[i][j] == 'S') start = { i, j, 0 };
            else if(maps[i][j] == 'L') labber = { i, j, 0 };
            else if(maps[i][j] == 'E') e = { i, j, 0 };
        }
    }
    BFS(start, maps, labber);
    BFS(labber, maps, e);
    
    if(!check_L || !check_E) answer = -1;
    
    return answer;
}