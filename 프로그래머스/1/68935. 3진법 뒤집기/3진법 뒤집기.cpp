#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int mul = 1;
    while(n >= mul) mul *= 3;
    mul /= 3;
    
    string thr = "";
    string reverse = "";
    
    while(mul > 0) {
        thr += to_string(n / mul);
        n -= mul * (n / mul);
        mul /= 3;
    }

    for(int i=thr.length()-1; i>=0; i--) reverse += thr[i];
    
    mul = 1; 
    for(int i=1; i<reverse.length(); i++) mul *= 3;
    
    for(int i=0; i<reverse.length(); i++) answer += mul * (reverse[i] - '0'), mul /= 3;
    
    return answer;
}