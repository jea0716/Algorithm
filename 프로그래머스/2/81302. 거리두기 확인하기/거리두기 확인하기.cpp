#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

bool BFS(int sx, int sy, vector<string> v) {
    queue<pair<int, pair<int, int>>> q;
    q.push({ 0, { sx, sy } });
    
    while(!q.empty()) {
        int cnt = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        
        if(cnt > 0 && v[x][y] == 'P') return false;
        
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= v.size()) continue;
            if(ny < 0 || ny >= v.size()) continue;
            if(nx == sx && ny == sy) continue;
            if(cnt >= 2) continue;
            if(v[nx][ny] == 'X') continue;
            
            q.push({ cnt + 1, { nx, ny } });
        }
    }
    
    return true;
}

bool solve(vector<string> v) {
    bool check = true;
    
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v[i].length(); j++) {
            if(v[i][j] == 'P' && !BFS(i, j, v)) check = false;
        }
    }
    
    return check;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(places.size(), 0);
    
    for(int k=0; k<places.size(); k++) {
        if(solve(places[k])) answer[k] = 1;
        else answer[k] = 0;
    }
    
    return answer;
}