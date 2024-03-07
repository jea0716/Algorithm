#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 1;
    for(int i=1; i<4; i++) {
        if(dots[0][0] == dots[i][0]) answer *= abs(dots[i][1] - dots[0][1]);
        if(dots[0][1] == dots[i][1]) answer *= abs(dots[i][0] - dots[0][0]);
    }
    
    return answer;
}