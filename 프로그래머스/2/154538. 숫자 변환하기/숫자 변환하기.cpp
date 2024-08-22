#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[1000001];

int solution(int x, int y, int n) {
    int answer = 0;
    
    queue<pair<int, int>> q;
    q.push({ 0, x });
    
    while(!q.empty()) {
        int cnt = q.front().first;
        int nn = q.front().second;
        q.pop();
        
        if(nn == y) {
            answer = cnt;
            return answer;
        }
        
        if(!visited[nn + n] && nn + n <= y) {
            visited[nn + n] = 1;
            q.push({ cnt + 1, nn + n });
        }
        
        if(!visited[nn * 2] && nn * 2 <= y) {
            visited[nn * 2] = 1;
            q.push({ cnt + 1, nn * 2 });
        }
        
        if(!visited[nn * 3] && nn * 3 <= y) {
            visited[nn * 3] = 1;
            q.push({ cnt + 1, nn * 3 });
        }
    }
    
    if(!visited[y]) answer = -1;
    
    return answer;
}