#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    for(int i=0; i<=str2.length() - str1.length(); i++) {
        bool check = true;
        for(int j=0; j<str1.length(); j++) {
            if(str2[i+j] != str1[j]) check = false;
        }
        if(check) answer = 1;
    }
    return answer;
}