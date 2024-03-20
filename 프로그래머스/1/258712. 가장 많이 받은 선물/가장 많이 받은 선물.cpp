#include <string>
#include <vector>

using namespace std;

int scope[51];
int map[51][51];
int give[51];

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    for(int i=0; i<gifts.size(); i++) {
        string tmp = "";
        int to, from;
        for(int j=0; j<gifts[i].length(); j++) {
            if(gifts[i][j] == ' ') {
                for(int k=0; k<friends.size(); k++) {
                    if(tmp == friends[k]) {
                        scope[k]++, to = k;
                    }
                }
                tmp = "";
            }
            else tmp += gifts[i][j];
            
            if(j == gifts[i].length() - 1) {
                for(int k=0; k<friends.size(); k++) {
                    if(tmp == friends[k]) {
                        scope[k]--, from = k;
                    }
                }
            }
        }
        map[to][from]++;
    }
    
    for(int i=0; i<friends.size(); i++) {
        for(int j=0; j<friends.size(); j++) {
            if(map[i][j] > map[j][i]) give[i]++;
            else if(map[i][j] == map[j][i] && scope[i] > scope[j]) give[i]++; 
        }
    }
    
    for(int i=0; i<friends.size(); i++) {
        if(answer < give[i]) answer = give[i];
    }
    
    return answer;
}