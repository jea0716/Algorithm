#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> sv;
    vector<int> v;
    bool check = true;
    int size, max_size = 0;
    string tmp = "";
    for(int i=1; i<s.length(); i++) {
        if(s[i] == '{') {
            check = true;
            size = 1;
            tmp = "";
        }
        else if(check && s[i] == '}') {
            check = false;
            max_size = max_size > size ? max_size : size;
            v.push_back(stoi(tmp));
            tmp = "";
            sv.push_back(v);
            v.clear();
            size = 0;
        }
        else if(check && s[i] == ',') {
            v.push_back(stoi(tmp));
            tmp = "";
            size++;
        }
        else {
            tmp += s[i];
        }
    }
    
    for(int i=1; i<=max_size; i++) {
        for(int j=0; j<sv.size(); j++) {
            if(sv[j].size() == i) {
                for(int k=0; k<sv[j].size(); k++) {
                    bool check = true;
                    for(int l=0; l<answer.size(); l++) {
                        if(answer[l] == sv[j][k]) check = false;
                    }
                    if(check) answer.push_back(sv[j][k]);
                }
            }
        }
    }
    return answer;
}