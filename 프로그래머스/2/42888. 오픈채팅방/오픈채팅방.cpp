#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, string> dic;
vector<pair<int, string>> chat;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    for(int i=0; i<record.size(); i++) {
        string tmp = "";
        int inout = 0;
        string id = "";
        string nickname = "";
        
        for(int j=0; j<record[i].length(); j++) {
            if(record[i][j] == ' ') {
                if(tmp == "Enter") inout = 1;
                else if(tmp == "Leave") inout = 2;
                else if(tmp == "Change") inout = 3;
                else {
                    if(inout != 0 && id == "") {
                        id = tmp;
                    }
                }
                tmp = "";
            }
            else {
                tmp += record[i][j];
            }
        }
        if(tmp != "" && id != "") nickname = tmp;
        else if(tmp != "" && id == "") id = tmp;
        
        if(inout == 1) {
            dic[id] = nickname;
            chat.push_back({ inout, id });
        }
        else if(inout == 2) {
            chat.push_back({ inout, id });
        }
        else if(inout == 3) {
            dic[id] = nickname;
        }
    }
    
    for(int i=0; i<chat.size(); i++) {
        string tmp = dic[chat[i].second];
        if(chat[i].first == 1) answer.push_back(tmp + "님이 들어왔습니다.");
        else answer.push_back(tmp + "님이 나갔습니다.");
    }
    
    return answer;
}