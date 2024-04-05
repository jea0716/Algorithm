#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    vector<int> v;
    queue<int> q;
    for(int i=1; i<=order.size(); i++) q.push(i);
    while(!q.empty()) {
        int n = q.front();
        q.pop();
        
        if(n == order[answer]) {
            answer++;
        }
        else {
            v.push_back(n);
        }
        while(v.size() > 0 && v.back() == order[answer]) {
            answer++;
            v.pop_back();
        }
    }
    
    return answer;
}