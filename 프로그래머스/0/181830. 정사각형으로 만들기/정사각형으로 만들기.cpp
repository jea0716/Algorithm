#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer;
    int max = arr.size();
    for(int i=0; i<arr.size(); i++) {
        if(arr[i].size() > max) max = arr[i].size();
    }
    for(int i=0; i<arr.size(); i++) {
        vector <int> v(max, 0);
        for(int j=0; j<arr[i].size(); j++) {
            v[j] = arr[i][j];
        }
        answer.push_back(v);
    }
    vector <int> v(max, 0);
    while(max > answer.size()) answer.push_back(v);
    return answer;
}