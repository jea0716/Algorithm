#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int complete = 0, answer = 0;
    
    for(int i=0; i<stations.size(); i++) {
        int tmp = stations[i] - w - 1;
        while(tmp > complete) {
            answer++;
            tmp -= 2 * w + 1;
        }
        complete = stations[i] + w;
    }
    
    while(complete < n) {
        complete += 2 * w + 1;
        answer++;
    }

    return answer;
}