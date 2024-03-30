#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> v1, v2;
    for(int i=0; i<str1.length()-1; i++) {
        string tmp = "";
        if(str1[i] >= 'a' && str1[i] <= 'z') tmp += str1[i] - 32;
        else if (str1[i] >= 'A' && str1[i] <= 'Z') tmp += str1[i];
        if(str1[i+1] >= 'a' && str1[i+1] <= 'z') tmp += str1[i+1] - 32;
        else if(str1[i+1] >= 'A' && str1[i+1] <= 'Z') tmp += str1[i+1];
        if(tmp.length() == 2) v1.push_back(tmp);
    }
    
    for(int i=0; i<str2.length()-1; i++) {
        string tmp = "";
        if(str2[i] >= 'a' && str2[i] <= 'z') tmp += str2[i] - 32;
        else if (str2[i] >= 'A' && str2[i] <= 'Z') tmp += str2[i];
        if(str2[i+1] >= 'a' && str2[i+1] <= 'z') tmp += str2[i+1] - 32;
        else if(str2[i+1] >= 'A' && str2[i+1] <= 'Z') tmp += str2[i+1];
        if(tmp.length() == 2) v2.push_back(tmp);
    }
    int cross = 0;
    bool check1[v1.size()], check2[v2.size()];
    for(int i=0; i<v1.size(); i++) check1[i] = false;
    for(int i=0; i<v2.size(); i++) check2[i] = false;
    for(int i=0; i<v1.size(); i++) {
        bool check = false;
        for(int j=0; j<v2.size(); j++) {
            if(!check && !check1[i] && !check2[j] && v1[i] == v2[j]) {
                check = true;
                check1[i] = true;
                check2[j] = true;
            }
        }
        if(check) cross++;
    }
    
    float tmp = (float)cross / (float)(v1.size() + v2.size() - cross);
    // cout << v1.size() << " " << v2.size() << " " << cross << endl;
    answer = tmp * 65536;
    
    if(v1.size() == 0 && v2.size() == 0) return 65536;
    
    return answer;
}