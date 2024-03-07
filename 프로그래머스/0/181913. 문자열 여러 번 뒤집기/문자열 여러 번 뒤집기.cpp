#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = my_string;
    for(int i=0; i<queries.size(); i++) {
        string tmp = "";
        for(int j=queries[i][1]; j>=queries[i][0]; j--) tmp += answer[j];
        for(int j=queries[i][0]; j<=queries[i][1]; j++) answer[j] = tmp[j - queries[i][0]];
    }
    return answer;
}