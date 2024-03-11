#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int last = n;
    int tmp;
    while(a <= last) {
        // answer += last / a;
        tmp = last / a;
        answer += tmp * b;
        last %= a;
        last += tmp * b;
        // 4, 13 - 2 11 - 2 7 - 1 5 - 1
    }
    return answer;
}