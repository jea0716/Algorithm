#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
bool visited[101][101];
map<int, int> area;

int BFS(int x, int y, vector<vector<int>> pic) {
    visited[x][y] = true;
    queue<pair<int, int>> q;
    q.push({ x, y });
    int cnt = 1;
    
    if(area.find(pic[x][y]) == area.end()) area.insert({pic[x][y], 1});
    
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx < 0 || nx >= pic.size()) continue;
            if(ny < 0 || ny >= pic[0].size()) continue;
            if(pic[nx][ny] != pic[x][y]) continue;
            if(visited[nx][ny]) continue;
            
            q.push({ nx, ny });
            area[pic[nx][ny]]++;
            cnt++;
            visited[nx][ny] = true;
        }
    }
    
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i=0; i<101; i++) {
        for(int j=0; j<101; j++) visited[i][j] = false;
    }
    area.clear();
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j] && picture[i][j] != 0) {
                int cnt = BFS(i, j, picture);
                if(cnt > max_size_of_one_area) {
                    max_size_of_one_area = cnt;
                }
                number_of_area++;
            }
        }
    }
    
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}