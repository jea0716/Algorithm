#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    vector<char> t;
    bool check;
    
    for(int i=0; i<skill_trees.size(); i++) {
        t.clear();
        check = true;
        
        for(int j=0; j<skill_trees[i].length(); j++) {
            for(int k=0; k<skill.length(); k++) {
                if(skill_trees[i][j] == skill[k]) t.push_back(skill[k]);
            }
        }
        
        for(int j=0; j<t.size(); j++) {
            if(t[j] != skill[j]) check = false;
        }
        
        if(check) answer++;
        
    }
    
    return answer;
}