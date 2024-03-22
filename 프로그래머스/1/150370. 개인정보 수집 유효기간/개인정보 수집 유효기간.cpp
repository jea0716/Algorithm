#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct YMD {
    int y, m, d;
};

struct T {
    string a;
    int terms;
};

int arr[27];

YMD getDay(string s) {
    YMD tmp = { 0, 0, 0 };
    string t = "";
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '.') {
            if(tmp.y == 0) { tmp.y = stoi(t), t = ""; } 
            else if(tmp.m == 0) { tmp.m = stoi(t); t = ""; }
        }
        else t += s[i];
    }
    tmp.d = stoi(t);
    return tmp;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    YMD TD = getDay(today);
    for(int i=0; i<terms.size(); i++) {
        string tmp = "";
        for(int j=2; j<terms[i].length(); j++) tmp += terms[i][j];
        arr[terms[i][0] - 'A'] = stoi(tmp);
    }
    
    for(int i=0 ;i<privacies.size(); i++) {
        string tmp = ""; YMD ymd;
        for(int j=0; j<privacies[i].length(); j++) {
            if(privacies[i][j] == ' ') ymd = getDay(tmp);
            tmp += privacies[i][j];
        }
        ymd.m += arr[privacies[i][privacies[i].length()-1] - 'A'];
        while(ymd.m > 12) {
            ymd.y++;
            ymd.m -= 12;
        }
        
        if(TD.y > ymd.y) answer.push_back(i + 1);
        else if(TD.y == ymd.y && TD.m > ymd.m) answer.push_back(i + 1);
        else if(
            TD.y == ymd.y &&
            TD.m == ymd.m &&
            TD.d >= ymd.d
               ) answer.push_back(i + 1);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}