#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int map[101][101];
bool visited[101][101];
int x, y, N, M;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int BFS(int x, int y)
{
    int count = 1e9;
    queue<pair<int, pair<int, int>>> q;
    q.push({ 0, { x, y } });
    visited[x][y] = true;
    
    while(!q.empty())
    {
        int cnt = q.front().first;
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        q.pop();
        
        if(map[cx][cy] == 2)
        {
            count = count < cnt ? count : cnt;
        }
        
        for(int i=0; i<4; i++)
        {
            int nx = cx;
            int ny = cy;
            while(
                nx + dx[i] >= 0 && nx + dx[i] < N &&
                ny + dy[i] >= 0 && ny + dy[i] < M &&
                map[nx + dx[i]][ny + dy[i]] != 1)
            {
                nx += dx[i];
                ny += dy[i];
            }
            
            if(visited[nx][ny]) continue;
            q.push({ cnt + 1, { nx, ny } });
            visited[nx][ny] = true;
        }
    }
    
    if(count == 1e9) return -1;
    else return count;
}

int solution(vector<string> board) 
{
    int answer = 0;
    N = board.size();
    M = board[0].length();
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(board[i][j] == 'D') map[i][j] = 1;
            else if(board[i][j] == 'G') map[i][j] = 2;
            else if(board[i][j] == 'R') x = i, y = j;
        }
    }
    
    answer = BFS(x, y);
    
    return answer;
}