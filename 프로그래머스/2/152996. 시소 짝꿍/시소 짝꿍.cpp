#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    vector<long long> v(1001, 0);
    
    for(int i=0; i<weights.size(); i++) v[weights[i]]++;
    
    for(int i=0; i<weights.size(); i++) {
        if(weights[i] % 2 == 0) {
            long long tmp = (weights[i] / 2) * 3;
            if(tmp <= 1000) answer += v[tmp];
        }
        
        if(weights[i] % 3 == 0) {
            long long tmp = (weights[i] / 3) * 4;
            if(tmp <= 1000) answer += v[tmp];
        }
        
        long long tmp = weights[i] * 2;
        if(tmp <= 1000) answer += v[tmp];
    }
    
    for(int i=100; i<=1000; i++) {
        if(v[i] >= 2) answer += (long long)(v[i] * (v[i] - 1)) / 2;
    }
    
    return answer;
}