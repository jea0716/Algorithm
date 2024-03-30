#include <string>
#include <vector>

using namespace std;

int answer;   
    
void DFS(int n, int total, vector<int> numbers, int target) {
    if(n == numbers.size() && total == target) {
        answer++;
        return;
    }
    
    if(n >= numbers.size()) return;
    DFS(n+1, total + numbers[n], numbers, target);
    DFS(n+1, total - numbers[n], numbers, target);
    return;
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    DFS(0, 0, numbers, target);
    return answer;
}