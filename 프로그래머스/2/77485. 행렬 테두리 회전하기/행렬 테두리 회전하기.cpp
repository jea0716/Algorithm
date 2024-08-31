#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int map[101][101];

int solve(int x1, int y1, int x2, int y2) 
{
    int first = map[x1][y1];
    int min_num = first;
    cout << first << endl;
    
    for(int i=x1+1; i<=x2; i++) 
    {
        map[i-1][y1] = map[i][y1];
        min_num = min_num < map[i][y1] ? min_num : map[i][y1];
    }
    
    for(int i=y1+1; i<=y2; i++)
    {
        map[x2][i-1] = map[x2][i];
        min_num = min_num < map[x2][i] ? min_num : map[x2][i];
    }
    
    for(int i=x2; i>x1; i--) 
    {
        map[i][y2] = map[i-1][y2];
        min_num = min_num < map[i-1][y2] ? min_num : map[i-1][y2];
    }
    
    for(int i=y2; i>y1; i--)
    {
        map[x1][i] = map[x1][i-1];
        min_num = min_num < map[x1][i-1] ? min_num : map[x1][i-1];
    }
    
    map[x1][y1+1] = first;
    
    return min_num;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) 
{
    vector<int> answer;
    
    for(int i=1; i<=rows; i++) 
    {
        for(int j=1; j<=columns; j++)
        {
            map[i][j] = j + (columns * (i - 1));
        }
    }
    
    for(int i=0; i<queries.size(); i++)
    {
        vector<int> tmp = queries[i];
        int min_num = solve(tmp[0], tmp[1], tmp[2], tmp[3]);
        answer.push_back(min_num);
    }
    
    return answer;
}