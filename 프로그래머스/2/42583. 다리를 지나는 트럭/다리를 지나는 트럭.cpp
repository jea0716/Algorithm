#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int total = 0;
    queue <int> q;
    for(int i=0; i<truck_weights.size(); i++) q.push(truck_weights[i]);
    queue <int> bridge;
    
    while(!q.empty()) {
        answer++;
        if(bridge.size() == bridge_length) {
            int tmp = bridge.front();
            total -= tmp;
            bridge.pop();
        }
        
        if(total + q.front() <= weight) {
            total += q.front();
            bridge.push(q.front());
            q.pop();
        }
        else {
            bridge.push(0);
        }
    }
    answer += bridge_length;
    
    return answer;
}