#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(long long n) {
    if(n < 2) return false;
    
    for(int i=2; i<=sqrt(n); ++i) {
        if(n % i == 0) return false;
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string s = "";
    while(n > 0) {
        s += to_string(n % k);
        n /= k;
    }
    reverse(s.begin(), s.end());
    
    string tmp = "";
    for(char c: s) {
        if(c == '0') {
            if(!tmp.empty() && isPrime(stoll(tmp))) {
                answer++;
            }
            tmp = "";
        }
        else {
            tmp += c;
        }
    }
    if(!tmp.empty() && isPrime(stoll(tmp))) answer++;
    
    return answer;
}