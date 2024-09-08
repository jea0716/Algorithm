#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int len = 0;
    
    for(int i=0; i<board.size(); i++) 
    {
        for(int j=0; j<board[i].size(); j++) 
        {
            if(board[i][j]) 
            {
                dp[i][j] = 1;
                len = 1;
            }
        }
    }

    for(int i=1; i<board.size(); i++)
    {
        for(int j=1; j<board[i].size(); j++)
        {
            if(board[i][j] && 
               board[i-1][j] && 
               board[i][j-1] && 
               board[i-1][j-1])
            {
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                if(dp[i][j] > len) len = dp[i][j];
            }
        }
    }
    
    answer = len * len;

    return answer;
}