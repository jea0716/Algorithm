#include <vector>
#include <queue>
using namespace std;

struct node {
    int x, y, cnt;
};

int answer = 987654321;
int N, M;
vector<vector<int>> map;
bool visited[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void BFS(int x, int y) {
    visited[x][y] = true;
    queue <node> q;
    q.push({ x, y, 1 });
    
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();
        if(x == N-1 && y == M-1) {
            answer = cnt;
            return;
        }
        
        for(int i=0; i<4; i++) {
            if(x + dx[i] < 0 || y + dy[i] < 0) continue;
            if(x + dx[i] >= N || y + dy[i] >= M) continue;
            
            if(
                map[x + dx[i]][y + dy[i]] == 1 &&
                !visited[x + dx[i]][y + dy[i]]
              ) {
                visited[x + dx[i]][y + dy[i]] = true;
                q.push({ x + dx[i], y + dy[i], cnt + 1 });
            }
        }
    }
}

int solution(vector<vector<int> > maps)
{
    map = maps;
    N = maps.size();
    M = maps[0].size();
    
    BFS(0, 0);
    
    if(answer == 987654321) answer = -1;
    
    return answer;
}