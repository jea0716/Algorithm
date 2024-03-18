#include <string>

using namespace std;

int sum(string s, char c) {
    int n = stoi(s);
    if(c == 'S') return n;
    if(c == 'D') return n * n;
    if(c == 'T') return n * n * n;
    
    return 0;
}

int solution(string dartResult) {
    int answer = 0;
    int prev = 0, now = 0;
    string tmp = "";
    for(int i=0; i<dartResult.length(); i++) {
        char result = dartResult[i];
        if(
            result == 'S' ||
            result == 'D' ||
            result == 'T' 
          ) {
            if(now != 0) prev = now;
            now = sum(tmp, result);
            answer += now;
            tmp = "";
        }
        
        else if(result == '*') answer += now + prev, now *= 2;
        else if(result == '#') answer -= now * 2, now *= -1;
        
        else if(result >= '0' && result <= '9') tmp += result;
    }
    return answer;
}