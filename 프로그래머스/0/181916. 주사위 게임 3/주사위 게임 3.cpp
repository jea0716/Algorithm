#include <string>
#include <vector>

using namespace std;

int dice[7];

int solution(int a, int b, int c, int d) {
    int answer = 0;
    int max = 0, n, m, p;
    dice[a]++; dice[b]++; dice[c]++; dice[d]++;
    bool check = true;
    for(int i=1; i<=6; i++) max = dice[i] > max ? dice[i] : max;
    if(max == 4) for(int i=1; i<=6; i++) if(dice[i] == 4) answer = 1111 * i;
    if(max == 3) {
        for(int i=1; i<=6; i++) {
            if(dice[i] == 3) n = i;
            if(dice[i] == 1) m = i;
        }
        answer = (10 * n + m) * (10 * n + m);
    }
    if(max == 2) {
        n = 0, m = 0, p = 0;
        for(int i=1; i<=6; i++) {
            if(n == 0 && dice[i] == 2) n = i;
            else if(n != 0 && dice[i] == 2) m = i;
            
            if(m == 0 && dice[i] == 1) m = i;
            else if(m != 0 && dice[i] == 1) p = i;
        }
        if(p == 0) answer = (n + m) * abs(n - m);
        else answer = m * p;
    }
    if(max == 1) for(int i=1; i<=6; i++) if(dice[i] == 1 && check) answer = i, check = false;
    
    return answer;
}