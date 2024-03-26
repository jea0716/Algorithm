#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for(long long i = left; i <= right; i++)
    {
        long long q = i / n;
        long long p = i % n;

        if(q < p) answer.push_back(p + 1);
        else answer.push_back(q + 1);
    }
    
    
    return answer;
}