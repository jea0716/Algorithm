#include <string>
#include <vector>

using namespace std;

int solution(int M, int N) {
    int answer = 0;
    int max = N > M ? N : M;
    int min = N < M ? N : M;
    answer = min - 1 + (max -1) * min;
    return answer;
}