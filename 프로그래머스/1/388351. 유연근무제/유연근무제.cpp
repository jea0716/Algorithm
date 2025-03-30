#include <string>
#include <vector>

using namespace std;

bool check;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    vector<int> renewalSchedules;
    vector<int> renewalTimelogs[timelogs.size()];
    vector<bool> weekend(7, false);
    
    for(int i=0; i<7; i++) {
        if((startday + i) % 7 == 6 || (startday + i) % 7 == 0) {
            weekend[i] = true;
        }
    }
    
    for(int i=0; i<schedules.size(); i++) {
        renewalSchedules.push_back((schedules[i] / 100 * 60) + (schedules[i] % 100) + 10);
    }
    
    for(int i=0; i<timelogs.size(); i++) {
        for(int j=0; j<timelogs[i].size(); j++) {
            renewalTimelogs[i].push_back((timelogs[i][j] / 100 * 60) + timelogs[i][j] % 100);
        }
    }
    
    for(int i=0; i<timelogs.size(); i++) {
        check = false;
        for(int j=0; j<renewalTimelogs[i].size(); j++) {
            if(!weekend[j] && renewalSchedules[i] < renewalTimelogs[i][j]) {
                check = true;
            }
        }
        
        if(!check) { answer++; }
    }
    
    return answer;
}