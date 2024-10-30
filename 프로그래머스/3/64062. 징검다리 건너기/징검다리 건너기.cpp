#include <string>
#include <vector>

using namespace std;

int solve(int n, vector<int> stones, int k) {
    int cnt = 0;
    for(int i=0; i<stones.size(); i++) {
        if(stones[i] - n <= 0) cnt++;
        else cnt = 0;
        
        if(cnt >= k) return true;
    }
    return false;
}

int solution(vector<int> stones, int k) {
    int start = 1, end = 200000000;
        
    while(start <= end) {
        int mid = (start + end) / 2;
        if(solve(mid, stones, k)) end = mid - 1;
        else start = mid + 1;
    }
    
    return start;
}