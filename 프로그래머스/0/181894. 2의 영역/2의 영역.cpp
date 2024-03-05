#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int s = -1, e = -1;
    bool check = true;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] == 2) {
            if(check) s = i, e = i, check = false;
            else e = i;
        }
    }

    if (s == -1 && e == -1) answer. push_back(-1);
    else {
        for(int i=s; i<=e; i++) answer.push_back(arr[i]);
    }
    return answer;
}