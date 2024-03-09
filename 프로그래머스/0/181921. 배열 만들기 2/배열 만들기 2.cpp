#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    for(int i=l; i<=r; i++) {
        string tmp = to_string(i);
        bool check = true;
        for(int j=0; j<tmp.length(); j++) {
            if(tmp[j] != '5' && tmp[j] != '0') check = false;
        }
        if(check) answer.push_back(i);
        
    }
    if(answer.empty()) answer.push_back(-1);
    return answer;
}