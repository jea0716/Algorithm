#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct node {
    int s, e, total;    
};

vector <node> v;

bool cmp(node n1, node n2) {
    return n1.total > n2.total;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0, cnt = 0, total = 0;
    
    while((picks[0] + picks[1] + picks[2]) * 5 < minerals.size()) {
        minerals.pop_back();
    }
    
    for(int i=0; i<minerals.size(); i++) {
        if(minerals[i] == "diamond") total += 25;
        else if(minerals[i] == "iron") total += 5;
        else if(minerals[i] == "stone") total += 1;
        
        cnt++;
        if(cnt == 5 || i == minerals.size() - 1) {
            v.push_back({ i - cnt + 1, i, total });
            cnt = 0;
            total = 0;
        }
    }
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0; i<v.size(); i++) {
            if(picks[0] != 0) {
                for(int j=v[i].s; j<=v[i].e; j++) {
                    if(minerals[j] == "diamond") answer += 1;
                    if(minerals[j] == "iron") answer += 1;
                    if(minerals[j] == "stone") answer += 1;
                }
                picks[0]--;
            }
            else if(picks[1] != 0) {
                for(int j=v[i].s; j<=v[i].e; j++) {
                    if(minerals[j] == "diamond") answer += 5;
                    if(minerals[j] == "iron") answer += 1;
                    if(minerals[j] == "stone") answer += 1;
                }
                picks[1]--;
            }
            else if(picks[2] != 0) {
                for(int j=v[i].s; j<=v[i].e; j++) {
                    if(minerals[j] == "diamond") answer += 25;
                    if(minerals[j] == "iron") answer += 5;
                    if(minerals[j] == "stone") answer += 1;
                }
                picks[2]--;
            }
    }
    
    return answer;
}