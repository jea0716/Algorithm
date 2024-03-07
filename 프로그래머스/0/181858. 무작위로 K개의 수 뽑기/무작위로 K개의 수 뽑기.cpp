#include <string>
#include <vector>

using namespace std;

int visited[100001];

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    for(int i=0; i<arr.size(); i++) {
        if(visited[arr[i]] == 0 && answer.size() < k) answer.push_back(arr[i]), visited[arr[i]] = 1;
    }
    while(answer.size() < k) {
        answer.push_back(-1);
    }
    return answer;
}