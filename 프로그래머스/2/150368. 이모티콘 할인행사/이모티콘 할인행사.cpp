#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visited[7][4];
int sales[] = { 10, 20, 30, 40 };
vector<int> answer(2, 0);

void check(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> sum(users.size(), 0);
    int plusUser = 0, maxSum = 0;
    
    for(int i=0; i<users.size(); i++)
    {
        for(int j=0; j<emoticons.size(); j++)
        {
            int sale = 0;
            for(int k=0; k<4; k++) 
            {
                if(visited[j][k]) sale = sales[k];
            }
            if(users[i][0] <= sale) sum[i] += emoticons[j] * (100 - sale) / 100; 
        }
    }
    
    for(int i=0; i<sum.size(); i++) 
    {
        if(sum[i] >= users[i][1]) 
        {
            sum[i] = 0;
            plusUser += 1;
            
        } else 
        {
            maxSum += sum[i];
        }
    }
    
    if(plusUser > answer[0] || plusUser == answer[0] && maxSum > answer[1])
    {
        answer[0] = plusUser;
        answer[1] = maxSum;
    }
    
    return ;
}

void DFS(int n, int cnt, vector<vector<int>> users, vector<int> emoticons) {
    if(n == cnt)
    {
        check(users, emoticons);
        
        return ;
    }

    for(int i=0; i<4; i++)
    {
        visited[n][i] = true;
        DFS(n + 1, cnt, users, emoticons);
        visited[n][i] = false;
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    DFS(0, emoticons.size(), users, emoticons);
    
    return answer;
}