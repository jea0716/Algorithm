#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> legend;
    for(int i=0; i<score.size(); i++) {
        if(legend.size() < k) legend.push_back(score[i]);
        else {
            if(legend[0] < score[i]) legend[0] = score[i];
        }
        sort(legend.begin(), legend.end());
        answer.push_back(legend[0]);
    }
    return answer;
}