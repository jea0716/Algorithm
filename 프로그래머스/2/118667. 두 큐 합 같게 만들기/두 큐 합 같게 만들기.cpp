#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

long long ll1 = 0;
long long ll2 = 0;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<int> q1, q2;
    for(int i=0; i<queue1.size(); i++) {
        q1.push(queue1[i]);
        ll1 += queue1[i];
    }
    for(int i=0; i<queue2.size(); i++) {
        q2.push(queue2[i]);
        ll2 += queue2[i];
    }
    
    while(answer <= queue1.size() * 3) {
        if(ll1 < ll2) {
            int tmp = q2.front();
            q2.pop();
            q1.push(tmp);
            ll1 += tmp;
            ll2 -= tmp;
            answer++;
        }
        else if(ll1 > ll2) {
            int tmp = q1.front();
            q1.pop();
            q2.push(tmp);
            ll2 += tmp;
            ll1 -= tmp;
            answer++;
        }
        else return answer;
    }
    answer = -1;
    
    return answer;
}