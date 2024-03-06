#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer =0 ;
    vector<char> v;
    
    for(int i=0; i<s.length(); i++) {
        if(v.size() > 0 && v[v.size()-1] == s[i]) v.pop_back();
        else v.push_back(s[i]);
    }
    
    if(v.empty()) answer = 1;
    else answer = 0;

    return answer;
}