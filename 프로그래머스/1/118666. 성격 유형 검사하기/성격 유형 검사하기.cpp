#include <string>
#include <vector>

using namespace std;

int arr[8]; // R, T, C, F, J, M, A, N

int check(char c) {
    if(c == 'R') return 0;
    else if(c == 'T') return 1;
    else if(c == 'C') return 2;
    else if(c == 'F') return 3;
    else if(c == 'J') return 4;
    else if(c == 'M') return 5;
    else if(c == 'A') return 6;
    else return 7;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    for(int i=0; i<survey.size(); i++) {
        int tmp = choices[i];
        if(tmp > 4) {
            int n = check(survey[i][1]);
            arr[n] += tmp - 4; 
        }
        else if(tmp < 4) {
            int n = check(survey[i][0]);
            arr[n] += 4 - tmp;
        }
    }
    answer += arr[0] >= arr[1] ? 'R' : 'T';
    answer += arr[2] >= arr[3] ? 'C' : 'F';
    answer += arr[4] >= arr[5] ? 'J' : 'M';
    answer += arr[6] >= arr[7] ? 'A' : 'N';
    return answer;
}