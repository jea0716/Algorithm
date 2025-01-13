#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool is_possible(int x, int y, int n, vector<vector<string>> park) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(park[x + i][y + j] != "-1") return false;
        }
    }
    
    return true;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    bool check = false;
    
    sort(mats.rbegin(), mats.rend());
    
    for(int k=0; k<mats.size(); k++) {
        if(check) continue;
        if(mats[k] > park.size()) continue;
        if(mats[k] > park[0].size()) continue;
        else {
            for(int i=0; i<=park.size()-mats[k]; i++) {
                for(int j=0; j<=park[i].size()-mats[k]; j++) {
                    if(is_possible(i, j, mats[k], park)) {
                        check = true;
                        answer = mats[k];
                    }
                }
            }
        }
    }
    
    return answer;
}