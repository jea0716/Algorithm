#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[20];
vector<int> v_info;
int n, answer = 0;

void solved(int cnt, int sheep, int wolf, queue<int> q) {
    if(v_info[cnt] == 0) sheep++;
    else wolf++;
    
    if(wolf >= sheep) return;
    answer = answer > sheep ? answer : sheep;
    
    for(int i=0; i<v[cnt].size(); i++) {
        q.push(v[cnt][i]);
    }
    
    for(int i=0; i<q.size(); i++) {
        int next = q.front();
        q.pop();
        solved(next, sheep, wolf, q);
        q.push(next);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {

    n = info.size();
    v_info.resize(n, 0);
    for(int i=0; i<n; i++) v_info[i] = info[i];
    for(int i=0; i<n-1; i++) v[edges[i][0]].push_back(edges[i][1]);
    
    queue<int> cur;
    
    solved(0, 0, 0, cur);
    
    return answer;
}