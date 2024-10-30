#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> m;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    
    for(int i=0; i<gems.size(); i++) {
        if(m.find(gems[i]) == m.end()) {
            m.insert({ gems[i], 0 });
        }
    }
    
    int s = 0, e = 0, cnt = 0, min_length = 1e9;
    
    while(s <= e) {
        if(cnt < m.size()) {
            if(e == gems.size()) break;
            if(m[gems[e]]++ == 0) {
                cnt++;
            }
            e++;
        } else {
            if(min_length > e - s) {
                min_length = e - s;
                answer[0] = s + 1;
                answer[1] = e;
            }
            if(--m[gems[s]] == 0) {
                cnt--;
            }
            s++;
        }
    }
    
    return answer;
}