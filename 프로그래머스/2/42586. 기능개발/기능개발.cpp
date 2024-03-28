#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i=0; i<progresses.size(); i++) q.push(i);
    while(!q.empty()) {
        for(int i=0; i<progresses.size(); i++) {
            if(progresses[i] < 100) progresses[i] += speeds[i];
        }
        int cnt = 0;
        while(q.size() > 0 && progresses[q.front()] >= 100) {
            q.pop();
            cnt++;
        }
        if(cnt > 0) answer.push_back(cnt);
    }
    
    return answer;
}