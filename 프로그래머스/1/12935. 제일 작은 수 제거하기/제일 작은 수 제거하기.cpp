#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    vector<int> tmp = arr;
    sort(tmp.begin(), tmp.end());
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] != tmp[0]) answer.push_back(arr[i]);
    }
    if(answer.size() == 0) answer.push_back(-1); 
    return answer;
}