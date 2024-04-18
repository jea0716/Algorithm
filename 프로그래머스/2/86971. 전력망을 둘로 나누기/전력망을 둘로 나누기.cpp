#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector< vector<int> > tree(101);
bool connection[101][101];
bool visited[101];
int answer = 100000000;

void solved(int n) {
    for(int i=1; i<=n; i++) visited[i] = false;
    
    queue <int> q;
    q.push(1);
    visited[1] = true;
    
    while(!q.empty()) {
        int nn = q.front();
        q.pop();
        
        for(int i=0; i<tree[nn].size(); i++) {
            if(!visited[tree[nn][i]] && !connection[nn][tree[nn][i]]) {
                q.push(tree[nn][i]);
                visited[tree[nn][i]] = true;;
            }
        }
    }
    int pos = 0, nag = 0;
    for(int i=1; i<=n; i++) {
        if(visited[i] == 0)  {
            nag++;
        }
        else {
            pos++;
        }
    }
    
    if(answer > abs(pos - nag)) answer = abs(pos - nag);
    
    return ;
}

int solution(int n, vector<vector<int>> wires) {
    for(int i=0; i<wires.size(); i++) {
        tree[wires[i][0]].push_back(wires[i][1]);
        tree[wires[i][1]].push_back(wires[i][0]);
    }
    for(int i=0; i<wires.size(); i++) {
        connection[wires[i][0]][wires[i][1]] = true;
        connection[wires[i][1]][wires[i][0]] = true;
        
        solved(n);
        
        connection[wires[i][0]][wires[i][1]] = false;
        connection[wires[i][1]][wires[i][0]] = false;
    }
    return answer;
}