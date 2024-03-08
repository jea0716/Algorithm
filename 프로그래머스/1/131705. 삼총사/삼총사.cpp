#include <string>
#include <vector>

using namespace std;

int answer;
int arr[3];
int visited[15];

void DFS(int count, vector<int> v) {
    if(count == 3) {
        if(arr[0] + arr[1] + arr[2] == 0) answer++;
        return;
    }
    
    for(int i=0; i<v.size(); i++) {
        if(visited[i] == 0) {
            visited[i] = 1;
            arr[count] = v[i];
            DFS(count + 1, v);
            visited[i] = 0;
        }
    }
}

int solution(vector<int> number) {
    DFS(0, number);
    
    return answer / 6;
}