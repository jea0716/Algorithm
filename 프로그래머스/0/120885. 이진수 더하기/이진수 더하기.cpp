#include <string>
#include <vector>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    int num1 = 0, num2 = 0;
    for(int i=0; i<bin1.length(); i++) {
        if(bin1[i] == '1') {
            int mul = 1;
            for(int j=0; j<bin1.length()-i-1; j++) mul *= 2;
            num1 += mul;
        }
    }
    
    for(int i=0; i<bin2.length(); i++) {
        if(bin2[i] == '1') {
            int mul = 1;
            for(int j=0; j<bin2.length()-i-1; j++) mul *= 2;
            num2 += mul;
        }
    }
    
    int sum = num1 + num2;
    
    int max = 1;
    while(max <= sum) max *= 2;
    max /= 2;
    while(max >= 1) {
        if(sum >= max) sum -= max, answer += '1';
        else answer += '0';
        max /= 2;
    }
    
    if(answer == "") answer = "0";
    
    return answer;
}