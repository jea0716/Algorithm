#include <string>
#include <vector>

using namespace std;

bool skip_list[26];

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(int i=0; i<skip.length(); i++) skip_list[skip[i] - 'a'] = true;
    for(int i=0; i<s.length(); i++) {
        char tmp = s[i];
        for(int j=0; j<index; j++) {
            tmp++;
            if(tmp > 'z') tmp -= 26;
            while(skip_list[tmp - 'a']) {
                tmp++;
                if(tmp > 'z') tmp -= 26;
            }
        }
        answer += tmp;
    }
    
    return answer;
}