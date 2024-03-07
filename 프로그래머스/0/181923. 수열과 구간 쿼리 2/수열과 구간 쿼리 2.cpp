#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for(int i=0; i<queries.size(); i++) {
        int diff = 99999999, num = -1;
        for(int j=queries[i][0]; j<=queries[i][1]; j++) {
            if(arr[j] > queries[i][2] && arr[j] - queries[i][2] < diff) diff = arr[j] - queries[i][2], num = arr[j];
        }
        answer.push_back(num);
    }
    return answer;
}