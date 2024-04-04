#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    priority_queue<int> pq(works.begin(), works.end());
    while(n > 0){
        if(pq.top() > 0){
            int tmp = pq.top();
            pq.pop();
            pq.push(tmp - 1);
            n--;
        }
        else{
            break;
        }
    }
    long long answer = 0;
    while(!pq.empty()){
        long long tmp = pq.top();
        pq.pop();
        answer += tmp * tmp;
    }  
    return answer;
}