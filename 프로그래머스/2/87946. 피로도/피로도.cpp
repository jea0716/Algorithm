#include <string>
#include <vector>

using namespace std;

bool visited[9];
int answer;

void DFS(int cnt, int Dsize, vector<vector<int>> D, int k) {
    if(answer < cnt) answer = cnt;
    
    for(int i=0; i<Dsize; i++) {
        if(!visited[i] && k >= D[i][0]) {
            visited[i] = true;
            DFS(cnt + 1, Dsize, D, k - D[i][1]);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    DFS(0, dungeons.size(), dungeons, k);
    return answer;
}