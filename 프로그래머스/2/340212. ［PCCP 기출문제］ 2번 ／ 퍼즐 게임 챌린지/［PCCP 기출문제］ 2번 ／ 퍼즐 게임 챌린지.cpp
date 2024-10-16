#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long check(long long n, vector<int> diffs, vector<int> times) {
    long long num = 0;
    int time_prev = 0;
    
    for(int i=0; i<diffs.size(); i++)
    {
        num += max(diffs[i] - n, (long long) 0) * (times[i] + time_prev);
        num += times[i];
        time_prev = times[i];
    }
    
    return num;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    long long min = 1, max = check(1, diffs, times);
    
    while(min < max) {
        long long mid = (min + max) / 2;
        long long tmp = check(mid, diffs, times);
        
        if(tmp <= limit) {
            max = mid;
        }
        
        else {
            min = mid + 1;
        }
    }
    
    return max;
}