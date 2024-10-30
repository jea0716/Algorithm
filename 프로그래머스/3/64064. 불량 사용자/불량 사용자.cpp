#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int answer = 0;
int visited[10];
unordered_map<string, int> m;

bool check(vector<string> user, vector<string> banned) {
    for(int i=0; i<user.size(); i++) {
        if(visited[i] != 0) {
            if(user[i].length() != banned[visited[i] - 1].length()) {
                return false;
            }
            for(int j=0; j<user[i].length(); j++) {
                char user_letter = user[i][j];
                char banned_letter = banned[visited[i] - 1][j];
                if(banned_letter == '*') continue;
                if(user_letter != banned_letter) return false;
            }
        }
    }
    return true;
}

void DFS(int n, int cnt, vector<string> user, vector<string> banned) {
    if(n == cnt) {
        string tmp = "";
        for(int i=0; i<user.size(); i++) {
            if(visited[i] == 0) tmp += '0';
            else tmp += '1';
        }
        
        if(m.find(tmp) == m.end() && check(user, banned)) {
            m.insert({ tmp, 0 });
            answer++;
        }
        
        return ;
    }
    
    for(int i=0; i<user.size(); i++) {
        if(visited[i] == 0) {
            visited[i] = n + 1;
            DFS(n + 1, cnt, user, banned);
            visited[i] = 0;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    DFS(0, banned_id.size(), user_id, banned_id);
    
    return answer;
}