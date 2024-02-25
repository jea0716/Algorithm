#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    string answer = "";
    
    int i = 0;
    if(participant.size() > 1) {
        while(participant[i] == completion[i]) {
            i++;
        }
    }
    answer = participant[i];
    
    return answer;
}