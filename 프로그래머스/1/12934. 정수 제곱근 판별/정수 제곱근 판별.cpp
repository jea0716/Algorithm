#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    while(answer * answer < n) {
        answer++;
    }
    if(answer * answer++ == n) answer *= answer;
    else answer = -1;
    return answer;
}