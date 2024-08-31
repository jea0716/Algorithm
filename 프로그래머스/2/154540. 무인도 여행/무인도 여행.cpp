#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

char map[101][101];
bool visited[101][101];
int N, M;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int BFS(int x, int y)
{
    int sum = 0;
    int num = map[x][y] -'0';  
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = 1;
    
    while(!q.empty()) 
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        sum += map[x][y] - '0';
        
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= N) continue;
            if(ny < 0 || ny >= M) continue;
            if(visited[nx][ny]) continue;
            if(map[nx][ny] == 'X') continue;
            
            q.push({ nx, ny });
            visited[nx][ny] = 1;
        }
    }
    
    return sum;
}

vector<int> solution(vector<string> maps) 
{
    vector<int> answer;
    N = maps.size();
    M = maps[0].length();
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++) 
        {
            map[i][j] = maps[i][j];
        }
    }
    
    for(int i=0; i<N; i++) 
    {
        for(int j=0; j<M; j++) 
        {
            if(map[i][j] != 'X' && !visited[i][j])
            {
                answer.push_back(BFS(i, j));
            }
        }
    }
    
    if(answer.empty()) answer.push_back(-1);
    
    sort(answer.begin(), answer.end());
    
    return answer;
}