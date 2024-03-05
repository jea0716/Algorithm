#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v;

void clear() {
    while(!v.empty()) v.pop_back();
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0; i<commands.size(); i++) {
        clear();
        for(int j=commands[i][0]-1; j<commands[i][1]; j++) v.push_back(array[j]);
        sort(v.begin(), v.end());
        answer.push_back(v[commands[i][2]-1]);

    }
    return answer;
}