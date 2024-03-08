#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> sum;
    for(int i=0; i<score.size(); i++) sum.push_back(score[i][0] + score[i][1]);
    sort(sum.rbegin(), sum.rend());
    
    vector<int> answer;
    for(int i=0; i<score.size(); i++) {
        bool check = true;
        for(int j=0; j<sum.size(); j++) {
            if(score[i][0] + score[i][1] == sum[j] && check) {
                answer.push_back(j + 1);
                check = false;
            }
        }
    }
    return answer;
}