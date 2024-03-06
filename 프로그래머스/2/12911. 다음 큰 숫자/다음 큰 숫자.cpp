#include <string>
#include <vector>

using namespace std;

int check(int n) {
    int n_count = 0, tmp = n, max = 1;
    while(max <= tmp) max *= 2;
    max /= 2;
    
    while(max >= 1) {
        if(max <= tmp) n_count++, tmp -= max;
        max /= 2;
    }
    
    return n_count;
}

int solution(int n) {
    int answer = n;
    int n_count = check(n);
    
    while(check(++answer) != n_count);
    
    return answer;
}