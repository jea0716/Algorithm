#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for(int i=0; i<scoville.size(); i++) q.push(scoville[i]);
    
    while(q.top() < K && q.size() > 1) {
        int tmp1 = q.top();
        q.pop();
        int tmp2 = q.top();
        q.pop();
        q.push(tmp1 + tmp2 * 2);
        answer++;
    }
    
    if(q.top() < K) answer = -1;
    
    return answer;
}