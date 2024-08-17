#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> dic;
int num = 1;

void setting(){
    for(int i=0; i<26; i++) {
        string tmp = "";
        tmp += 'A' + i;
        dic[tmp] = num++;
    }
}

vector<int> solution(string msg) {
    setting();
    
    vector<int> answer;
    
    string tmp = "";
    for(int i=0; i<msg.length(); i++) {
        tmp += msg[i];
        if(dic[tmp] == 0) {
            dic[tmp] = num++;
            tmp = tmp.substr(0, tmp.length() - 1);
            answer.push_back(dic[tmp]);
            tmp = "";
            i--;
        }
    }
    answer.push_back(dic[tmp]);
    
    return answer;
}