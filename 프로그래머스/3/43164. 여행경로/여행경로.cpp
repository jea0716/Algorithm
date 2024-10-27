#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
bool visited[10001];
bool isAnswer;

void DFS(string start, int cnt, vector<vector<string>> tickets) {
    answer.push_back(start);
    
    if(cnt == tickets.size()) {
        isAnswer = true;
    }
    
    for(int i=0; i<tickets.size(); i++) {
        if(visited[i]) continue;
        if(tickets[i][0] == start) {
            visited[i] = true;
            DFS(tickets[i][1], cnt + 1, tickets);
            
            if(!isAnswer) {
                answer.pop_back();
                visited[i] = false;
            }
        }
        
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    DFS("ICN", 0, tickets);
    
    return answer;
}