#include <string>
#include <vector>
#include <queue>

using namespace std;

struct node {
    string s;
    int cnt;
};

bool visited[51];

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    queue<node> q;
    q.push({ begin, 0 });
    
    while(!q.empty()) {
        string s = q.front().s;
        int cnt = q.front().cnt;
        q.pop();
        
        if(s == target) {
            return cnt;
        }
        
        for(int i=0; i<words.size(); i++) {
            int check = 0;
            if(!visited[i]) {
                for(int j=0; j<words[i].length(); j++) {
                    if(s[j] != words[i][j]) check++;
                }
                if(check == 1) {
                    q.push({ words[i], cnt + 1 });
                    visited[i] = true;
                }
            }
        }
    }
    
    return answer;
}