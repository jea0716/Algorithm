#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    bool check = true;
    while(check) {
        int tmp = 0;
        for(int i=0; i<citations.size(); i++) {
            if(answer <= citations[i]) tmp++;
        }
        cout << tmp << endl;
        if(answer <= tmp) answer++;
        else check = false;
    }
    answer--;
    
    return answer;
}