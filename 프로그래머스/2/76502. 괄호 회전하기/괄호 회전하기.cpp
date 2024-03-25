#include <string>
#include <vector>
#include <iostream>

using namespace std;

int big, middle, small;
vector <char> v;

bool check(string s, int n) {
    v.clear();
    for(int i=n; i<s.length(); i++) {
        v.push_back(s[i]);
        if(v.size() > 1) {
            if(v[v.size()-2] == '[' && v[v.size()-1] == ']') {
                v.pop_back();
                v.pop_back();
            }
            if(v[v.size()-2] == '{' && v[v.size()-1] == '}') {
                v.pop_back();
                v.pop_back();
            }
            if(v[v.size()-2] == '(' && v[v.size()-1] == ')') {
                v.pop_back();
                v.pop_back();
            }
        }
    }
    for(int i=0; i<n; i++) {
        v.push_back(s[i]);
        if(v.size() > 1) {
            if(v[v.size()-2] == '[' && v[v.size()-1] == ']') {
                v.pop_back();
                v.pop_back();
            }
            if(v[v.size()-2] == '{' && v[v.size()-1] == '}') {
                v.pop_back();
                v.pop_back();
            }
            if(v[v.size()-2] == '(' && v[v.size()-1] == ')') {
                v.pop_back();
                v.pop_back();
            }
        }
    }
    
    if(v.empty()) return true;
    else return false;
}

int solution(string s) {
    int answer = 0;
    if(s.length() % 2 == 0) {
        for(int i=0; i<s.length(); i++) {
            if(check(s, i)) answer++;
        }
    }
    return answer;
}