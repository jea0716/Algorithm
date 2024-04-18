#include <string>
#include <vector>

using namespace std;

int sol(int num) {
    if(num < 10) return min(num, 10 - num + 1);
    int a = num % 10, b = 10 - num % 10;
    return min(sol((num - a) / 10) + a, sol((num + b) / 10) + b);
}

int solution(int storey) {

    return sol(storey);
}