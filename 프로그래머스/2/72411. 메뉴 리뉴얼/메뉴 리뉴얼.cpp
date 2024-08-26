#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> m;
int max_order;

void recursive(int n, int cnt, string t, string s) {
    if(n == cnt) {
        if(m.find(t) == m.end()) {
            m.insert({ t, 1 });
        }
        else m[t]++;
        
        if(m[t] > max_order) max_order = m[t];
        
        return ;
    }
    
    for(int i=0; i<s.length(); i++) {
        char c = s[i];
        bool check = true;
        for(int j=0; j<t.length(); j++) {
            if(t[j] >= c) check = false;
        }
        if(check) recursive(n + 1, cnt, t + c, s);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i=0; i<course.size(); i++) {
        int num = course[i];
        m.clear();
        max_order = 0;
        for(int j=0; j<orders.size(); j++) {
            if(orders[j].length() < num) continue;
            recursive(0, num, "", orders[j]);
        }
        for(auto i: m) {
            if(max_order >= 2 && i.second == max_order) {
                answer.push_back(i.first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}