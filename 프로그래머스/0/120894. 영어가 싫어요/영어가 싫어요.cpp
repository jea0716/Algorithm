#include <string>
#include <vector>

using namespace std;

long long solution(string numbers) {
    long long answer = 0;
    string num = "";
    string tmp = "";
    for(int i=0; i<numbers.length(); i++) {
        if(tmp == "zero") answer *= 10, answer += 0, tmp = "";
        else if(tmp == "one") answer *= 10, answer += 1, tmp = "";
        else if(tmp == "two") answer *= 10, answer += 2, tmp = "";
        else if(tmp == "three") answer *= 10, answer += 3, tmp = "";
        else if(tmp == "four") answer *= 10, answer += 4, tmp = "";
        else if(tmp == "five") answer *= 10, answer += 5, tmp = "";
        else if(tmp == "six") answer *= 10, answer += 6, tmp = "";
        else if(tmp == "seven") answer *= 10, answer += 7, tmp = "";
        else if(tmp == "eight") answer *= 10, answer += 8, tmp = "";
        else if(tmp == "nine") answer *= 10, answer += 9, tmp = "";
        
        tmp += numbers[i];
    }
    if(tmp == "zero") answer *= 10, answer += 0, tmp = "";
    else if(tmp == "one") answer *= 10, answer += 1, tmp = "";
    else if(tmp == "two") answer *= 10, answer += 2, tmp = "";
    else if(tmp == "three") answer *= 10, answer += 3, tmp = "";
    else if(tmp == "four") answer *= 10, answer += 4, tmp = "";
    else if(tmp == "five") answer *= 10, answer += 5, tmp = "";
    else if(tmp == "six") answer *= 10, answer += 6, tmp = "";
    else if(tmp == "seven") answer *= 10, answer += 7, tmp = "";
    else if(tmp == "eight") answer *= 10, answer += 8, tmp = "";
    else if(tmp == "nine") answer *= 10, answer += 9, tmp = "";
    
    return answer;
}