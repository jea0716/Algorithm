#include <string>
#include <vector>
#include <queue>

using namespace std;

int map[102][102];
bool visited[102][102];

int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

int BFS(int x, int y, int a, int b)
{
    int num = 1e9;
    queue<pair<int, pair<int, int>>> q;
    q.push({ 0, { x, y } });
    visited[x][y] = 1;
    
    while(!q.empty())
    {
        int cnt = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        
        bool check = false;
        for(int i=0; i<8; i++) 
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx > 101) continue;
            if(ny < 0 || ny > 101) continue;
            if(map[nx][ny] == 0) check = true;
        }
        
        if(!check) continue;
        else {visited[x][y] = 1;}
        
        if(x == a && y == b)
        {
            if(num > cnt / 2) num = cnt / 2;
        }
        
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx > 101) continue;
            if(ny < 0 || ny > 101) continue;
            if(map[nx][ny] == 0) continue;
            if(visited[nx][ny]) continue;
            
            q.push({ cnt + 1, { nx, ny } });
        }
    }
    
    
    return num;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    for(int i=0; i<rectangle.size(); i++)
    {
        for(int x=rectangle[i][0] * 2; x<=rectangle[i][2] * 2; x++)
        {
            for(int y=rectangle[i][1] * 2; y<=rectangle[i][3] * 2; y++)
            {
                map[x][y] = 1;
            }
        }
    }
    
    int answer = BFS(characterX * 2, characterY * 2, itemX * 2, itemY * 2);
    
    return answer;
}