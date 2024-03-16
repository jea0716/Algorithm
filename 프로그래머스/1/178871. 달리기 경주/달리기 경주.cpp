#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer = players;
    
    map<string, int> m;
    
    for (int i=0; i<players.size(); i++) {
        m[players[i]] = i;
    }
    
    for(int i=0;i<callings.size();i++){
        
        int locate = m[callings[i]];
        
        m[answer[locate-1]] +=1;
        m[callings[i]] -=1;
        
        string tmp = answer[locate];
        answer[locate] = answer[locate-1];
        answer[locate-1] = tmp;   
    }
    
    return answer;
}