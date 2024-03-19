#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    bool check = true;
    int error = 0;
    map <string, int> m;
    
    for(int i=0; i<words.size()-1; i++) {
        if(words[i][words[i].length()-1] != words[i+1][0] && check) {
            answer[0] = (i + 2) % n == 0 ? n : (i + 2) % n;
            answer[1] = (i + 2) % n == 0 ? (i + 2) / n : (i + 2) / n + 1;
            check = false;
            error = i + 2;
        }
    }
    
    for(int i=0; i<words.size(); i++) {
        if(m.find(words[i]) == m.end()) m.insert({ words[i], i });
        else {
            int tmp1 = (i + 1) % n == 0 ? n : (i + 1) % n;
            int tmp2 = (i + 1) % n == 0 ? (i + 1) / n : (i + 1) / n + 1;
            if(tmp2 < answer[1] || answer[1] == 0) {
                answer[0] = tmp1;
                answer[1] = tmp2;
            }
            else if(tmp2 == answer[1] && tmp1 < answer[0]) {
                answer[0] = tmp1;
                answer[1] = tmp2;
            }
        }
    }

    return answer;
}