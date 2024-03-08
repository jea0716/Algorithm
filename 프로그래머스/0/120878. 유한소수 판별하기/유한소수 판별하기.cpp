#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    int gcd = 0;
    int min = a > b ? b : a;
    for(int i=1; i<=min; i++) {
        if(a % i == 0 && b % i == 0) gcd = i;
    }
    int m = b / gcd;
    while(m % 5 == 0) m /= 5;
    while(m % 2 == 0) m /= 2;
    if(m != 1) answer = 2;
    else answer = 1;
    return answer;
}