#include <string>
#include <vector>

using namespace std;

int used1[11], used2[11];

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    for(int i=0; i<goal.size(); i++) {
        for(int j=0; j<cards1.size(); j++) {
            if(goal[i] == cards1[j]) used1[j] = 1;
        }
        for(int j=0; j<cards2.size(); j++) {
            if(goal[i] == cards2[j]) used2[j] = 1;
        }
        
        bool check = true;
        for(int j=0; j<cards1.size(); j++) {
            if(used1[j] == 0) check = false;
            if(!check && used1[j] == 1) answer = "No";
        }
        
        check = true;
        for(int j=0; j<cards2.size(); j++) {
            if(used2[j] == 0) check = false;
            if(!check && used2[j] == 1) answer = "No";
        }
    }
    return answer;
}