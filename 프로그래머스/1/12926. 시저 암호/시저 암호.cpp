#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i=0; i<s.length(); i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            answer += 'a' + (s[i] - 'a' + n) % 26;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z') {
            answer += 'A' + (s[i] - 'A' + n) % 26;
        }
        else answer += s[i];
    }
    return answer;
}