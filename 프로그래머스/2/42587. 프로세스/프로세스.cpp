#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    bool visited[priorities.size()];
    bool check = true;
    queue <int> q;
    for(int i=0; i<priorities.size(); i++) {
        visited[i] = false;
        q.push(i);
    }
    while(!q.empty()) {
        int n = q.front();
        q.pop();
        
        int priority = 0;
        for(int i=0; i<priorities.size(); i++) {
            if(!visited[i] && priorities[i] > priority) {
                priority  = priorities[i];
            }
        }
        
        if(priorities[n] == priority) {
            visited[n] = true;
            if(check) answer++;
            if(n == location) check = false;
        }
        else q.push(n);
    }
    
    return answer;
}