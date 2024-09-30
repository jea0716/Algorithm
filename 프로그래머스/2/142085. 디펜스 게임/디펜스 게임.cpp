#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    
    priority_queue<int, vector<int>, greater<int> > q;
    
    for(int i=0; i<enemy.size(); i++)
    {
        q.push(enemy[i]);
        
        if(q.size() > k)
        {
            n -= q.top();
            q.pop();
        }
        if(n < 0) return i;
    }
    
    return enemy.size();
}