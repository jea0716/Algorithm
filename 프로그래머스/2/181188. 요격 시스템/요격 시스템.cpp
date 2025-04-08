#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    
    sort(targets.begin(), targets.end());
    
    int start = targets[0][0], end = targets[0][1];
    
    for(int i=1; i<targets.size(); i++) {
        if(targets[i][0] < end) {
            if(targets[i][1] < end) end = targets[i][1];
        } else {
            answer++;
            start = targets[i][0];
            end = targets[i][1];
        }
    }
    
    
    return answer;
}