#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    bool check = true;
    for(int i=1; i<=n; i++) {
        if(n % i == 1 && check) answer = i, check = false;
    }
    return answer;
}