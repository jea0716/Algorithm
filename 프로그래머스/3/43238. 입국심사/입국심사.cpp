#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    
    long long answer = 0, start = 0, end = 1e18, mid, tmp;
    
    while(start <= end)
    {
        mid = (start + end) / 2;
        tmp = 0;
        
        for(int i=0; i<times.size(); i++)
        {
            tmp += mid / (long long) times[i];
        }
        
        if(tmp >= n)
        {
            end = mid - 1;
            answer = mid;
        }
        
        else 
        {
            start = mid + 1;
        }
    }
    
    return answer;
}