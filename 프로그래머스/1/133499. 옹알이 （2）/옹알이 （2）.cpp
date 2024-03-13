#include <string>
#include <vector>

using namespace std;

string bab[] = { "aya", "ye", "woo", "ma" };
vector<string> v;

bool dul() {
    for(int i=0; i<v.size()-1; i++) {
        if(v[i] == v[i+1]) return false;
    }
    return true;
}

bool check(string s) {
    for(int i=0; i<4; i++) if(bab[i] == s) return true;
    return false;
}

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(int i=0; i<babbling.size(); i++) {
        string tmp = "";
        for(int j=0; j<babbling[i].length(); j++) {
            tmp += babbling[i][j];
            if(check(tmp)) v.push_back(tmp), tmp = "";
        }
        if(tmp == "" && dul()) answer++;
        while(!v.empty()) v.pop_back();
    }
    
    return answer;
}